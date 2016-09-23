<?php
    /*require_once('data_base.php');
    if ($_SESSION[logged_in] == false)
        header('Location : connexion.php');
    $images = "";
    $query = "SELECT * FROM gallery";
    $prep = $pdo->prepare($query);
    $prep->execute();
    
    $arr = $prep->fetch();
    while ($arr != false)
    {
        $images += "<img src=\"".$arr['picture']."\" onclick=getRightDiv()/>\n";
        $arr = $prep->fetch();
    }*/
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
                                <textarea name="comment" maxlength=255 placeholder="Votre commentaire..."></textarea>
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
            <img src="http://www.gettyimages.pt/gi-resources/images/Homepage/Hero/PT/PT_hero_42_153645159.jpg" onclick="getRightDiv()"/>
            <img src="http://assets.barcroftmedia.com.s3-website-eu-west-1.amazonaws.com/assets/images/recent-images-11.jpg" onclick="getRightDiv()"/>
            <img src="http://www.wanimo.com/veterinaire/cache/multithumb_thumbs/b_300_0_16777215_00_images_articles_chat_chat-hyperesthsie.jpg" onclick="getRightDiv()"/>
            <img src="http://www.geluck.com/dpics/slideshow/LART-ET-LE-CHAT-C1-3D.png" onclick="getRightDiv()"/>
            <img src="http://www.wanimo.com/veterinaire/cache/multithumb_thumbs/b_300_0_16777215_00_images_articles_chat_chat-hyperesthsie.jpg" onclick="getRightDiv()"/>
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