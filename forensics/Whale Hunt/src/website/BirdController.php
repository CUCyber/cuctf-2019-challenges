<?php


class BirdController {

  function random_bird($complete = false) {
    $bird_names = $this->all_bird_names();
    $random_bird_name = $bird_names[rand(0,count($bird_names)-1)];
    $random_bird = new Bird($random_bird_name);
    if ($complete) {
      while ($random_bird->isComplete() === false) {
        $random_bird_name = $bird_names[rand(0,count($bird_names)-1)];
        $random_bird = new Bird($random_bird_name);
      }
    }
    return $random_bird;
  }

  function all_bird_names() {
    $txt_file = file_get_contents('Birds.txt');
    return explode("\n", $txt_file);
  }

}
