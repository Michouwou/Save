<?php
    require_once('data_base.php');
    if ($_SESSION['logged_in'] == false)
        redirect('Location : connexion.php');
    $images = "";
    $query = "SELECT * FROM gallery";
    $prep = $pdo->prepare($query);
    $prep->execute();
    
    while ($arr = $prep->fetch())
            $images = "<img id=\"".$arr['id']."\" src=\"data:image/png;charset=utf-8;base64,".
                        addcslashes($arr['picture'], "'\"}")."\" onclick=\"getRightDiv(".$arr['id'].")\"/>\n".$images;
?>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <link rel="stylesheet" type="text/css" href="galery.css"/>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
        <title>
            Galery
        </title>
    </head>
    <body>
        <div id="header">
            <div id="fast_access">
                <a href="log_out.php">Se déconnecter</a>
                <a href="camagru.php">Camagru</a>
            </div>
        </div>
        <div class="display" id="commenting">
            <div id="like">
                <button id="button1" onclick="likePicture()"></button>
                <button id="button2" onclick="unlikePicture()"></button>
            </div>
            <div id="comment">
                <div id="form">
                    <table>
                        <tr style="height:90%;">
                            <td>
                                <textarea id="text_comment" name="comment" placeholder="Votre commentaire..."></textarea>
                            </td>
                        </tr>
                        <tr style="height:10%;">
                            <td>
                                <input type="submit" name="Envoyer!" value="Envoyer!" onclick="getComment()">
                            </td>
                        </tr>
                    </table>
                </div>
                <hr/>
                <div id="actual_contain">
                    <table id="actual">
                        
                    </table>
                </div>
            </div>
        </div>
        <div class="commentaries" id="selecting">
            <div class="select">
                Selectionnez
                <br>une
                <br>image
           </div>
        </div>
        <div id="pictures">
            <?php
                if ($images != "")
                    echo $images;
            ?>
        </div>
        <div id="footer">
            
        </div>
    </body>
    <script type="text/javascript">
        var current_id = "";
        var comment = document.getElementById('text_comment');
        var like = document.getElementById('button1');
        var dislike = document.getElementById('button2');
        var glob_id = <?php echo $_SESSION['id_user']; ?> ;
        var tab;

        function getRightDiv(id)
        {
            var div = document.getElementById("commenting");
            div.className = "commentaries";
            div = document.getElementById("selecting");
            div.className = "display";
            if (current_id != "")
                document.getElementById(current_id).className = "";
            current_id = id;
            document.getElementById(current_id).className = "selection";
            $.ajax(
            {
                type: 'POST',
                url: 'http://localhost:8080/Camagru/getComments.php',
                dataType: 'text',
                data:
                {
                    id_picture : current_id ,
                },
                success: function(data)
                {
                    affect(data);
                }
            });
        }

        function affect(data)
        {
            tab = data;
            var actual = document.getElementById("actual");
            actual.innerHTML = tab ;
        }

        function getComment()
        {
            $.ajax(
            {
                type: 'POST',
                url: 'http://localhost:8080/Camagru/Comment_handler.php',
                dataType: 'text',
                data:
                {
                    id_picture : current_id ,
                    id_user : String(glob_id) ,
                    comment : comment.value ,
                },
                success: function () 
                {
                    comment.value = "";
                }
            });
            getRightDiv(current_id);
        }

        function unlikePicture()
        {
            $.ajax(
            {
                type: 'POST',
                url: 'http://localhost:8080/Camagru/Comment_handler.php',
                dataType: 'text',
                data:
                {
                    id_picture : current_id ,
                    id_user : String(glob_id) ,
                    like : "-1" ,
                },
                success: function () 
                {}
            });
            getRightDiv(current_id);
        }

        function likePicture()
        {
            $.ajax(
            {
                type: 'POST',
                url: 'http://localhost:8080/Camagru/Comment_handler.php',
                dataType: 'text',
                data:
                {
                    id_picture : current_id ,
                    id_user : String(glob_id) ,
                    like : "1" ,
                },
                success: function () 
                {}
            });
            getRightDiv(current_id);
        }
    </script>
</html>