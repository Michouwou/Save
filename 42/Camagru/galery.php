<?php
    require_once('data_base.php');
    if ($_SESSION[logged_in] == false)
        header('Location : connexion.php');
    $images = "";
    $query = "SELECT * FROM gallery";
    $prep = $pdo->prepare($query);
    $prep->execute();
    
    while ($arr = $prep->fetch())
            $images = $images."<img src=\"data:image/png;charset=utf-8;base64,".addcslashes($arr['picture'], "'\"}")."\" onclick=\"getRightDiv()\"/>\n";
?>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <link rel="stylesheet" type="text/css" href="galery.css"/>
        <title>
            Galery
        </title>
    </head>
    <body>
        <div id="header">
            <div id="fast_access">
                <table>
                    <tr>
                        <td style="position:absolute;">
                            <a href="log_out.php">Se déconnecter</a>
                        </td>
                        <td style="position:static;">
                             <a href="galery.php">Galerie</a>
                        </td>
                    </tr>
                </table>
            </div>
        </div>
        <div class="display" id="commenting">
            <div id="like">
                <button id="button1" onclick="likePicture()">I like it!</button>
                <button id="button2" onclick="unlikePicture()">I don't like it!</button>
            </div>
            <div id="comment">
                <form id="form">
                    <table>
                        <tr style="height:90%;">
                            <td>
                                <textarea name="comment" placeholder="Votre commentaire..."></textarea>
                            </td>
                        </tr>
                        <tr style="height:10%;">
                            <td>
                                <input type="submit" name="Envoyer!" value="Envoyer!">
                            </td>
                        </tr>
                    </table>
                            
                </form>
            </div>
        </div>
        <div class="commentaries" id="selecting">
            <div class="select" style="padding-top:10%;">
                Selectionnez
            </div>
            <div class="select">
                une
            </div>
            <div class="select">
               image!
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
        function getRightDiv()
        {
                var div = document.getElementById("commenting");
                div.className = "commentaries";
                div = document.getElementById("selecting");
                div.className = "display";
        }
    </script>
</html>