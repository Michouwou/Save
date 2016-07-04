<?php
    require_once("Header.php");
?>
<html>
    <head>
        <link rel="stylesheet" href="MyLife.css" type="text/css" />
        <meta charset="UTF-8">

            <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
            <script src="sss/sss.min.js"></script>
            <link rel="stylesheet" href="sss/sss.css" type="text/css" media="all">

            <script>
            jQuery(function($) {
            $('.slider').sss();
            });
            </script>

    </head>
    <body>
       <div class="cursus">
           <p>
               <h1 style="text-decoration:underline;">Bon, premièrement, qu'est ce que l'école 42?</h1>
               <br />
               &emsp;&emsp;L'école 42, c'est un établissement fondé par Xavier Niel (fondateur d'Iliad-Free), Nicolas Sadirac (ancien directeur général d'Epitech), Kwame Yamgnane et Florian Bucher (anciens cadres d'Epitech), qui a ouvert en Juillet 2013.
               Cette école qui n'en est pas vraiment une a pour objectif de former des dévéloppeurs les plus polyvalents et compétents possibles, afin de répondre au mieux au besoin grandissant du marché de l'informatique, du web, du design (et autres).
               Le fonctionnement n'a quasiment rien à voir avec les Universités, Classes Préparatoires, ou BTS et autres formations dites "classiques".
               <br />
               &emsp;&emsp;Tout fonctionne par projet. Au début chaque étudiant est au niveau zéro et doit progresser à son rythme en effectuant des programmes informatiques en tous genres.
               Il y a des quêtes nommées "Black Holes" qui nous donnent une certaine marge de manoeuvre par rapport au temps (ex. En tout un étudiant a 3 mois à compter de sa rentrée pour être niveau 1).
               La formation compte également deux stages professionnels de 3 à 6 mois chacun, ayant pour but de mettre en pratique toutes les compétences acquises durant le cursus.
               <br />
               &emsp;&emsp;Il n'y a pas de professeurs, pas d'horaires, pas de matières ou de salles de classe et encore moins de "devoirs" (à proprement parler).
               <br /><br />
               <span style="font-weight:bold;">Pour plus d'infos, voyez les quelques liens suivants :</span>
               <br />
                <ul class="links">
                   <li>
                       <a href="https://fr.wikipedia.org/wiki/42_(%C3%A9coles)">Sur Wikipédia</a>
                   </li>
                   <li>
                       <a href="http://www.42.fr/">Le Site Officiel</a>
                   </li>
                </ul>
           </p>
           <hr>
           <div>
           <div class="slider">
                <img src="img/42cluster.jpg" />
                <img src="img/42infographie.png" />
                <img src="img/42PiscinePHP.png" />
            </div>
            </div>
       </div>
    </body>
</html>