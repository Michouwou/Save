var video = document.querySelector("#videoElement");
var canvas = document.querySelector("#my_canvas");
var data2;
var inner_images;
var id = 0;
var current_png = "";
var contain = document.getElementById('shooter');
var videoElement = document.getElementById('videoElement');
var Selected;
var click = document.getElementById('shoot');


navigator.getUserMedia = navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia || navigator.oGetUserMedia;

if (navigator.getUserMedia)       
    navigator.getUserMedia({video: true}, handleVideo, videoError);

click.onmousedown = function()
{
    click.id = "timer";
}

window.onresize = function()
{
    resize();
};

function show_pane(id)
{
    document.getElementById(id).style.border = "6px solid red";
}

function unshow_pane(id)
{
    document.getElementById(id).style.border = "";
}

function upload_file()
{
    make_inner();
    var link = document.createElement("input");
    link.type = "file";
    link.click();
    var is_jpg = 0;
    link.onchange = function ()
    {
        var file = link.files[0];
        console.log(file);
        if (file.name.match(/.*(\.png|\.jpg)/))
        {
            var reader = new FileReader();
            reader.onloadend = function()
            {
                if (file.name.match(/.*\.jpg/))
                    is_jpg = 1;
                data2 = reader.result.replace(/^data:image\/(png|jpg);base64,/, "");
                getImage_up(glob_id, current_png, data2, is_jpg);
            }
            if (file)
            {
                reader.readAsDataURL(file);
            }
        }
        else
        {
            alert("Vous ne pouvez uploader que des fichiers en extension jpg ou png!");
        }
    }
}

function get_last_image()
{
    if (confirm("Voulez-vous télécharger la photo que vous venez de sélectionner??") == true)
    {
        var a = document.createElement("a");
        var data = document.getElementById(Selected).src;
        var name = 'camagru_picture_' + Selected;
        if (window.navigator.msSaveOrOpenBlob)
            window.navigator.msSaveOrOpenBlob(file, name);
        else
        {
            a.href = data;
            a.download = name;
            document.body.appendChild(a);
            a.click();
            setTimeout(function()
            {
                document.body.removeChild(a);
                window.URL.revokeObjectURL(url);  
            }, 0); 
        }
        var last = document.getElementById(Selected);
        if (last)
            last.className = "inner_images";
        Selected = "";
        document.getElementById('download').style.display = "none";
    }
}

function select(id)
{
    var last = document.getElementById(Selected);
    if (last)
        last.className = "inner_images";
    Selected = id;
    document.getElementById('download').style.display = "block";
    document.getElementById(Selected).className = "selected";
}

function superpose(id)
{
    var image = document.getElementById(id).cloneNode();
    var to_delete = document.getElementById('actual');
    document.getElementById("shoot").style.display = "flex";
    document.getElementById("upload").style.display = "block";
    click.onclick = function()
    {
        getImage(glob_id, current_png);
    }
    if (current_png != "")
        document.getElementById(current_png).className = "super";
    if (to_delete)
        contain.removeChild(to_delete);
    var x = videoElement.offsetWidth;
    var y = videoElement.offsetHeight;
    image.style.width = x.toString()+"px";
    image.style.height = y.toString()+"px";
    image.style.position = 'absolute';
    image.className = "";
    image.id = 'actual';
    current_png = id;
    document.getElementById(current_png).className = "activepng";
    contain.insertBefore(image, contain.firstChild);;
}

function resize()
{
    var image = document.getElementById('actual');
    if (image)
    {
        var x = videoElement.offsetWidth;
        var y = videoElement.offsetHeight;
        image.style.width = x.toString()+"px";
        image.style.height = y.toString()+"px";
    }
}

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
    var temp = click.onclick;
    click.onclick = "";
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
        },
        complete: function()
        {
            click.onclick = temp;
        }
    });
}

function getImage_up(glob_id, current_png, img, is_jpg)
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
            jpg : String(is_jpg),
        },
        success: function(data)
        {
            if (is_jpg == 1)
                data3 = "data:image\/jpeg;base64," + data;
            else
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
    click.id = "shoot";
}

function videoError(e)
{
    alert("You have to allow access to your video device to use this application!")
}