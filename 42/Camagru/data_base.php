<?php
    require_once('utils.php');
        try
        {
            session_start();
            if ($_SESSION['logged_in'] == false)
            {
                $_SESSION['logged_in'] = false;
            }
            $connection = 'mysql:host=localhost;dbname=db';
            $utf8= array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8");
            $pdo = new PDO($connection, 'michouwou', '', $utf8);
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        }
        catch(PDOException $exception)
        {
            $msg = 'ERREUR PDO dans ' . $exception->getFile() . ' L.' . $exception->getLine() . ' : ' . $exception->getMessage();
            die($msg);
        }
?>