<?php
        try
        {
            if (!isset($_SESSION))
            {
                session_start();
                $_SESSION['logged_in'] = false;
            }
            $connection = 'mysql:host=127.0.0.1;port=3306;dbname=mysql';
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