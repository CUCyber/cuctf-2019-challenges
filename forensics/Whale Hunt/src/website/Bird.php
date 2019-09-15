<?php

class Bird {

    public $name = "";
    public $image = "";
    public $description = "";
    public $wiki_url = "";

    function __construct($bird_name) {
       $this->name = $bird_name;
       $this->image = $this->generate_image_URL();
       $this->description = $this->generate_info_text();
       $this->wiki_url = $this->generate_wikipedia_URL();
     }

     function print_info() {
       $img = $this->image;
       echo "<img src='$img' />";
       echo "<br />";
       $wiki_url = $this->wiki_url;
       echo "<a href='$wiki_url' target='_blank'>$this->name</a>";
       echo "<br />";
       echo $this->description;
       echo "<br />";
       echo "<br />";
       echo "<br />";
     }

     public function isComplete() {
       if (filter_var($this->image, FILTER_VALIDATE_URL) === false) {
         $img_exists = false;
       } else {
         $img_file_headers = @get_headers($this->image);
         $img_exists = !($file_headers[0] == 'HTTP/1.1 404 Not Found');
       }

       if (filter_var($this->wiki_url, FILTER_VALIDATE_URL) === false) {
         $link_exists = false;
       } else {
         $link_file_headers = @get_headers($this->wiki_url);
         $link_exists = !($file_headers[0] == 'HTTP/1.1 404 Not Found');
       }

       $description_exists = true;
       if (stripos($description,'This is a redirect from a title') !== false || $this->description == "") {
           $description_exists = false;
       }
       $complete = $img_exists && $link_exists && $description_exists;
       return $complete;
      }

     private function generate_wikipedia_URL() {
       $formattedBirdString = str_replace("'", "%27", str_replace(" ", "_", $this->name));
       $url = "https://en.wikipedia.org/wiki/".$formattedBirdString;
       return $url;
     }

    private function generate_image_URL() {
      $formattedBirdString = str_replace(" ", "%20", $this->name);
      $url =  "http://en.wikipedia.org/w/api.php?action=query&prop=pageimages&format=json&pithumbsize=500&titles=".$formattedBirdString;
      $data = file_get_contents($url);
      $json_array = json_decode($data, TRUE);
      $thumb = "empty";
      foreach($json_array["query"]["pages"] as $k => $v) {
        $thumb = $v["thumbnail"]["source"];
      }
      return $thumb;
    }

    private function generate_info_text() {
      $base_url = "https://en.wikipedia.org/w/api.php?format=json&action=query&prop=extracts&exintro=&explaintext=&titles=";
      $formattedBirdString = str_replace(" ", "%20", $this->name);
      $url = $base_url.$formattedBirdString;
      $data = file_get_contents($url);
      $json_array = json_decode($data, TRUE);
      $info_text = "No info.";
      foreach($json_array["query"]["pages"] as $k => $v) {
        $info_text = $v["extract"];
      }
      return $info_text;
    }


}
