<?php
    require_once("data_base.php");
    if ($_SESSION['logged_in'] == false)
        header('Location : connexion.php');
?>

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="camagru.css">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
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
    <script type="text/javascript">
        var video = document.querySelector("#videoElement");
        var canvas = document.querySelector("#my_canvas");
        var tab = [];
 
        navigator.getUserMedia = navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia || navigator.oGetUserMedia;
 
        if (navigator.getUserMedia)       
            navigator.getUserMedia({video: true}, handleVideo, videoError);
 
        function handleVideo(stream)
        {
            video.src = window.URL.createObjectURL(stream);
        }
        
        function getImage()
        {
            var context = canvas.getContext('2d');
            canvas.width = 200;
            canvas.height = 200;
            context.drawImage(video, 0, 0, 200, 200);
            var data = canvas.toDataURL('image/png');
            var inner_images = document.querySelector("#inner_images");
            context.clearRect(0, 0, canvas.width, canvas.height);
            inner_images.height = 200;
            inner_images.width = 200;
            inner_images.setAttribute('src', data);
            tab.push(data);
        }
        
        window.onbeforeunload = saveData;
        window.onunload = saveData;
        
        function saveData()
        {
            var to_send = JSON.stringify(tab);
            var request = new XMLHttpRequest();
            request.open("POST", "JSON_Handler.php", true);
            request.setRequestHeader("Content-type", "application/json");
            request.send("data=".to_send);
        }
 
        function videoError(e)
        {
            alert("You have to allow access to your video device to use this application!")
        }
    </script>
</html>