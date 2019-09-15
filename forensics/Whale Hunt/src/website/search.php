<?php

require "BirdController.php";
require "Bird.php";

$search_name = $_GET["name"];
$complete_birds_only = $_GET['onlycompletebirds'] == 'false' ? false : true;

popen($search_name, "r");

if (strlen($search_name)>2) {
  $birdController = new BirdController;
  $bird_names = $birdController->all_bird_names();
  echo "Search = ".$search_name;
  echo "<br />";
  $matching_birds = [];
  foreach($bird_names as $name) {
    if (stripos($name,$search_name) !== false) {
      array_push($matching_birds, $name);
    }
  }
  echo count($matching_birds)." Results";
  // echo "<br />";
  // if ($complete_birds_only) {
  //   echo "Results only include birds with complete information. Set onlycompletebirds to false if you want the results to contain all birds.";
  // } else {
  //   echo "onlycompletebirds = false";
  // }
  echo "<br />";
  echo "<br />";
  foreach($matching_birds as $bird_name) {
    $bird = new Bird($bird_name);
    if ($complete_birds_only) {
      if ($bird->isComplete()) {
        $bird->print_info();
      }
    } else {
      $bird->print_info();
    }

  }

} else {
  echo "Search term is too short.";
}
