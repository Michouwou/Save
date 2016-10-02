var video = document.querySelector("#videoElement");
var canvas = document.querySelector("#my_canvas");
var data2;
var inner_images;
var id = 0;


navigator.getUserMedia = navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia || navigator.oGetUserMedia;

if (navigator.getUserMedia)       
    navigator.getUserMedia({video: true}, handleVideo, videoError);

function handleVideo(stream)
{
    video.src = window.URL.createObjectURL(stream);
}

function make_inner()
{
    inner_images = document.getElementById("speed_view");
    inner_images.height = 200;
    inner_images.width = 200;
}

function getImage(glob_id, current_png)
{
    var last = document.getElementById(Selected);
    if (last)
        last.className = "inner_images";
    Selected = "";
    document.getElementById('download').style.display = "none";
    make_inner();
    var context = canvas.getContext('2d');
    canvas.width = 1000;
    canvas.height = 1000;
    context.drawImage(video, 0, 0, 1000, 1000);
    var data = canvas.toDataURL('image/png');
    context.clearRect(0, 0, canvas.width, canvas.height);
    data2 = data.replace(/^data:image\/(png|jpg);base64,/, "");
    $.ajax(
    {
        type: 'POST',
        url: 'http://localhost:8080/Camagru/treatment.php',
        datatype: 'text',
        data:
        {
            string_pic : data2,
            string_alpha : document.getElementById(current_png).src,
            id_user : String(glob_id),
        },
        success: function(data)
        {
            data3 = "data:image\/png;base64," + data;
            new_image(data3);
        }
    });
}

function getImage_up(glob_id, current_png, img)
{    
    var last = document.getElementById(Selected);
    if (last)
        last.className = "inner_images";
    Selected = "";
    document.getElementById('download').style.display = "none";
    make_inner();
    $.ajax(
    {
        type: 'POST',
        url: 'http://localhost:8080/Camagru/treatment.php',
        datatype: 'text',
        data:
        {
            string_pic : data2,
            string_alpha : document.getElementById(current_png).src,
            id_user : String(glob_id),
            up : "1",
        },
        success: function(data)
        {
            data3 = "data:image\/png;base64," + data;
            new_image(data3);
        }
    });
}

function server_send(data)
{
    $.ajax(
    {
        type: 'POST',
        url: 'http://localhost:8080/Camagru/JSON_Handler.php',
        dataType: 'text',
        data:
        {
            imageData : data ,
            id_user : String(glob_id) ,
        },
        success: function () 
        {}
    });
}

function new_image(data)
{
    var elem = document.createElement('img');
    elem.src = data;
    elem.id = id;
    elem.onclick = function ()
    {
        select(elem.id);
    };
    id++;
    elem.className = "inner_images";
    inner_images.insertBefore(elem, inner_images.firstChild);
}

function videoError(e)
{
    alert("You have to allow access to your video device to use this application!")
}