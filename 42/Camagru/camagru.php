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
                                        <div style="height:15vmin">
                                        <div id="images">
                                            <img src="png_frame_1.png" class="super" id='1' onclick="superpose('1')"/>
                                            <img src="png_frame_2.png" class="super" id='2' onclick="superpose('2')"/>
                                            <img src="png_frame_3.png" class="super" id='3' onclick="superpose('3')"/>
                                            <img src="png_frame_4.jpg" class="super" id='4' onclick="superpose('4')"/>
                                            <img src="png_frame_5.png" class="super" id='5' onclick="superpose('5')"/>
                                            <img src="png_frame_6.png" class="super" id='6' onclick="superpose('6')"/>
                                        </div>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <div id="shooter">
                                            <video autoplay="true" id="videoElement">
                                            </video>
                                            <button id="shoot" onclick="getImage(glob_id, current_png)"></button>
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
        <script type="text/javascript">
            var glob_id = <?php echo "\"".strval($_SESSION['id_user'])."\""; ?> ;
            var current_png;
            var contain = document.getElementById('shooter');
            var videoElement = document.getElementById('videoElement');
            window.onresize = function()
            {
                resize();
            };

            function superpose(id)
            {
                var image = document.getElementById(id).cloneNode();
                var to_delete = document.getElementById('actual');
                if (to_delete)
                    contain.removeChild(to_delete);
                var x = videoElement.offsetWidth;
                var y = videoElement.offsetHeight;
                image.style.width = x.toString()+"px";
                image.style.height = y.toString()+"px";
                image.style.height = videoElement.style.height.toString()+"px";
                image.style.position = 'absolute';
                image.className = "";
                image.id = 'actual';
                current_png = id;
                contain.insertBefore(image, contain.firstChild);;
            }

            function resize()
            {
                var image = document.getElementById('actual');
                if (image)
                {
                    var x = videoElement.offsetWidth;
                    var y = videoElement.offsetHeight;
                    console.log(x);
                    image.style.width = x.toString()+"px";
                    image.style.height = y.toString()+"px";
                }
            }
        </script>
        <script type="text/javascript" src="get_image.js">
        </script>
    </body>
</html>