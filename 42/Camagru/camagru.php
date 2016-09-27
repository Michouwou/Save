<?php
    require_once("data_base.php");
    if ($_SESSION['logged_in'] == false)
         redirect('connexion.php');

?>

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="camagru.css">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
        <title>
            Camagru
        </title>
    </head>
    <body>
        <div id="header">
            <div id="fast_access">
                <a href="log_out.php">Se déconnecter</a>
                <a href="galery.php">Galerie</a>
            </div>
        </div>
        <div id="main_content">
            <table style="width:100%;">
                <tr>
                    <td style="width:50%;">
                        <div class="side">
                            <table>
                                <tr>
                                    <td>
                                        <div id="images">
                                            <img src="test_1_image.png" class="super"/>
                                            <img src="test_1_image.png" class="super"/>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <div id="shooter">
                                            <video autoplay="true" id="videoElement">
                                            </video>
                                            <button id="shoot" onclick="getImage(glob_id)"></button>
                                            <canvas id="my_canvas">
                                            </canvas>
                                        </div>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </td>
                    <td id='test'>
                        <div class="side speed_view">
                        </div>
                    </td>
                </tr>
            </table>
        </div>
        <div id="footer">
            
        </div>
        <script>
            var glob_id = <?php echo "\"".strval($_SESSION['id_user'])."\""; ?> ;
            console.log("camagru " + glob_id);
        </script>
        <script type="text/javascript" src="get_image.js">
        </script>
    </body>
</html>