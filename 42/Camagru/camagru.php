<?php
    require_once("data_base.php");
    // if ($_SESSION['logged_in'] == false)
    //     header('Location : connexion.php');
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
            <div class="side">
                <table>
                    <tr>
                        <td>
                            <div id="images">
                            </div>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <div id="shooter">
                                <video autoplay="true" id="videoElement">
                                </video>
                                <button id="shoot" onclick="getImage()"></button>
                                <canvas id="my_canvas">
                                    
                                </canvas>
                            </div>
                        </td>
                    </tr>
                </table>
            </div>
            <div class="side speed_view">
                <img id="inner_images"/>
            </div>
        </div>
        <div id="footer">
            
        </div>
    </body>
    <script type="text/javascript" src="get_image.js"></script>
</html>