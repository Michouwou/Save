var video = document.querySelector("#videoElement");
var canvas = document.querySelector("#my_canvas");
var data2;


alert("blop");
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
    data2 = data.replace(/^data:image\/(png|jpg);base64,/, "");
    $.ajax(
    {
        type: 'POST',
        url: 'http://localhost:8080/Camagru/JSON_Handler.php',
        dataType: 'text',
        data:
        {
            imageData : data2 ,
        },
        success: function () 
        {
            alert("SUCCESS");
        }
    });
}

function videoError(e)
{
    alert("You have to allow access to your video device to use this application!")
}