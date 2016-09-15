<?php
    require_once("data_base.php");
    if ($_POST['data'] != NULL)
    {
        $result = json_decode($_POST['data']);
        while (($var = $result->fetch()) != false)
        {
            $query = "INSERT INTO galery ('json_rep') VALUES (?)";
            $prep = $pdo->prepare($query);
            $prep->bindValue(1, base64_encode($var), PARAM::STR);
            $prep->execute();
        }
    }
?>