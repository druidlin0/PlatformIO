//web-assets.h
#include <Arduino.h>

const char index_html[] PROGMEM = R"===(
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    a {
      font-family: 'Arial'; display: block; width: 80%%; margin: 12px auto; 
      font-size: 2em; padding: 12px; border: 1px solid gray; border-radius: 12px;
      background-color: #444; text-align: center; color: white; text-decoration: none; 
    }
    img {
      width: 100%%; display: none; margin: 3em 0;
    }
    [data-status=on] .on, [data-status=off] .off {
      display: block;
    }
    div.main {
      width: 80%%; max-width: 480px; margin: 0 auto; 
    }
  </style>
</head>
<body>
  <div class="main">
  <div onclick="toggleLed()" id="toggleButton" data-status="%LED_ONOFF%">
    <img class="on" src="/bulb-on.svg" />
    <img class="off" src="/bulb-off.svg" />
  </div>
  <a href='/reset-wifi'>RESET WIFI</a>
  <iframe id=ajaxFrame style='display:none'></iframe>
  </div>
  <script>
    var b = document.getElementById('toggleButton');
    var f = document.getElementById('ajaxFrame');
    function toggleLed() {
      let newState = (b.getAttribute('data-status') == 'on' ? 'off' : 'on');
      f.src = '/led/' + newState;
      b.setAttribute('data-status', newState);
    }
  </script>
</body>
</html>
)===";

const char bulb_svg[] PROGMEM = R"===(<?xml version="1.0" encoding="iso-8859-1"?>
<svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
   viewBox="0 0 283.994 283.994" style="enable-background:new 0 0 283.994 283.994;" xml:space="preserve">
<g>
<path style="fill:%COLOR1%;" d="M122.086,132.667c3.136,3.199,8.236,3.199,11.372,0c3.168-3.168,3.168-8.331,0-11.499
l-2.217-2.281h24.772l-18.215,18.437c-1.489,1.521-2.344,3.611-2.344,5.765v54.74h-27.813V169.35
c0-2.914-1.552-5.607-4.055-7.064c-23.949-13.938-38.806-39.914-38.806-67.823c0-43.114,34.624-78.181,77.199-78.181
s77.231,35.068,77.231,78.181c0,28.732-15.522,55.088-40.484,68.805c-2.598,1.394-4.213,4.15-4.213,7.159v27.401h-22.967
v-51.382l29.587-29.936c2.281-2.344,2.978-5.829,1.742-8.87s-4.181-5.037-7.444-5.037h-63.609
c-3.263,0-6.209,1.996-7.444,5.037s-0.57,6.526,1.742,8.87L122.086,132.667z"/>
<path style="fill:#2D213F;" d="M64.78,94.464c0,27.908,14.857,53.884,38.806,67.823c2.503,1.457,4.055,4.15,4.055,7.064
v28.478h27.813v-54.74c0-2.154,0.855-4.245,2.344-5.765l18.215-18.437h-24.772l2.217,2.281c3.168,3.168,3.168,8.331,0,11.499
c-3.136,3.199-8.236,3.199-11.372,0l-15.966-16.156c-2.312-2.344-2.978-5.829-1.742-8.87
c1.235-3.041,4.181-5.037,7.444-5.037h63.609c3.263,0,6.209,1.996,7.444,5.037s0.539,6.526-1.742,8.87l-29.587,29.936v51.382
h22.967v-27.401c0-3.009,1.616-5.765,4.213-7.159c24.962-13.717,40.484-40.073,40.484-68.805
c0-43.114-34.656-78.181-77.231-78.181S64.78,51.35,64.78,94.464z M235.303,94.464c0,33.072-17.011,63.546-44.698,80.652
v30.886c0,0.539-0.063,1.077-0.158,1.584c2.914,3.358,4.752,7.729,4.752,12.544v0.634c0,4.055-1.267,7.793-3.421,10.897
c2.154,3.073,3.421,6.811,3.421,10.866v0.634c0,10.517-8.426,19.038-18.785,19.038h-8.553v0.697
c0,11.626-9.345,21.098-20.844,21.098h-10.675c-11.499,0-20.844-9.472-20.844-21.098v-0.697h-10.707
c-10.359,0-18.785-8.521-18.785-19.038v-0.634c0-4.055,1.299-7.793,3.421-10.866c-2.122-3.104-3.421-6.842-3.421-10.897
v-0.634c0-5.29,2.154-10.074,5.607-13.526c-0.032-0.19-0.063-0.412-0.063-0.602v-32.09
c-26.546-17.296-42.86-47.327-42.86-79.448C48.688,42.385,90.535,0,141.98,0C193.456,0,235.303,42.385,235.303,94.464z
M179.106,243.16v-0.634c0-1.489-1.204-2.724-2.693-2.724h-71.624c-1.489,0-2.693,1.235-2.693,2.724v0.634
c0,1.521,1.204,2.756,2.693,2.756h71.624C177.904,245.916,179.106,244.681,179.106,243.16z M179.106,220.764v-0.634
c0-1.489-1.204-2.724-2.693-2.724h-71.624c-1.489,0-2.693,1.235-2.693,2.724v0.634c0,1.521,1.204,2.756,2.693,2.756h71.624
C177.904,223.52,179.106,222.284,179.106,220.764z M151.768,262.896v-0.697h-20.179v0.697c0,2.629,2.154,4.783,4.752,4.783
h10.675C149.646,267.679,151.768,265.525,151.768,262.896z"/>
<path style="fill:#C5CBCF;" d="M176.414,245.916H104.79c-1.489,0-2.693-1.235-2.693-2.756v-0.634
c0-1.489,1.204-2.724,2.693-2.724h71.624c1.489,0,2.693,1.235,2.693,2.724v0.634
C179.106,244.681,177.904,245.916,176.414,245.916z"/>
<path style="fill:#EAEEEF;" d="M176.414,223.52H104.79c-1.489,0-2.693-1.235-2.693-2.756v-0.634
c0-1.489,1.204-2.724,2.693-2.724h71.624c1.489,0,2.693,1.235,2.693,2.724v0.634
C179.106,222.284,177.904,223.52,176.414,223.52z"/>
<path style="fill:#C5CBCF;" d="M151.768,262.199v0.697c0,2.629-2.122,4.783-4.752,4.783h-10.675
c-2.598,0-4.752-2.154-4.752-4.783v-0.697H151.768z"/>
<path style="fill:%COLOR2%;" d="M103.586,162.286c2.503,1.457,4.055,4.15,4.055,7.064v28.478h27.813v-54.74
c0-2.154,0.855-4.245,2.344-5.765l1.438-1.454c-28.497-0.653-52.709-8.499-70.458-16.71
C74.702,137.086,86.939,152.599,103.586,162.286z"/>
<path style="fill:%COLOR2%;" d="M163.156,134.701l-11.61,11.746v51.382h22.967v-27.401c0-3.009,1.616-5.765,4.213-7.159
c17.29-9.5,30.037-25.067,36.249-43.285C196.874,128.141,179.49,132.718,163.156,134.701z"/>
</g>
</svg>
)===";