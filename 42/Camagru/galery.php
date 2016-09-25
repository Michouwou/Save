<?php
    require_once('data_base.php');
    if ($_SESSION['logged_in'] == false)
        redirect('Location : connexion.php');
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
                <hr/>
                <div id="actual_contain">
                    <table id="actual">
                        <tr>
                            <td>
                                J'adore cette photo, elle est geante!
                            </td>
                        </tr>
                        <tr>
                            <td>
                                Quelqu'un pourrait me trouver le nom de l'artiste svp, ca fait un bout de temps que je le cherche et impossible de mettre la main dessus, du coup si    quelqu'un a une idee, faites le moi savoir svp
                            </td>
                        </tr>
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
        function getRightDiv()
        {
                var div = document.getElementById("commenting");
                div.className = "commentaries";
                div = document.getElementById("selecting");
                div.className = "display";
        }
    </script>
</html>