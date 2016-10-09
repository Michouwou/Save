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
                <a href="my_images.php">Mes images</a>
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
                                        <div style="height:15vmin">
                                        <div id="images">
                                            <img src="png_frame_1.png" class="super" id='a' onclick="superpose('a')"/>
                                            <img src="png_frame_2.png" class="super" id='b' onclick="superpose('b')"/>
                                            <img src="png_frame_3.png" class="super" id='c' onclick="superpose('c')"/>
                                            <img src="png_frame_4.jpg" class="super" id='d' onclick="superpose('d')"/>
                                            <img src="png_frame_5.png" class="super" id='e' onclick="superpose('e')"/>
                                            <img src="png_frame_6.png" class="super" id='f' onclick="superpose('f')"/>
                                        </div>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <div id="shooter">
                                            <video autoplay="true" id="videoElement">
                                            </video>
                                            <button id="shoot"></button>
                                            <canvas id="my_canvas">
                                            </canvas>
                                        </div>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </td>
                    <td id='test'>
                        <div class="side speed_view" id="speed_view">
                        </div>
                    </td>
                </tr>
                <tr id="b_row"><td><div style="display:flex;">
            <div id="buttons">
                <button class="download" id="download" onclick="get_last_image()">
                    Download
                </button>
                <button id="upload" class="download" onclick="upload_file()">
                    Upload
                </button>
            </div>
        </div></td></tr>
            </table>
        
        </div>
        <div id="footer">
            <p onmouseover="show_pane('images')" onmouseout="unshow_pane('images')">Vous devez selectionner un element a superposer pour pouvoir prendre une photo ou en envoyer une</p>
            <br/>
            <p onmouseover="show_pane('speed_view')" onmouseout="unshow_pane('speed_view')">Si une photo vous plait, vous pouvez la telecharger en cliquant dessus puis sur "Download"</p>
        </div>
        <script type="text/javascript">
            var glob_id = <?php echo "\"".strval($_SESSION['id_user'])."\""; ?> ;
        </script>
        <script type="text/javascript" src="get_image.js">
        </script>
    </body>
</html>