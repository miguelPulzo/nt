/**
 * Created by root on 20/01/16.
 */
$( document).ready( function(){
  $("#btn_md5").on("click", function(){ getMd5(); });
  $("#btn_sha1").on("click", function(){ getSha1(); });
  $("#btn_genmd5").on("click", function(){ genMd5(); });
  $("#btn_gensha1").on("click", function(){ genSha1(); });
  $("#btn_fut").on("click", function(){ getFut(); });
  $("#btn_fdt").on("click", function(){ getFdt(); });
  $("#btn_ct").on("click", function(){ getCt(); });
  $("#btn_cd").on("click", function(){ getCd(); });
  $("#btn_cb64").on("click", function(){ getCb64(); });
  $("#btn_dcb64").on("click", function(){ getDcb64(); });
  $("#btn_genpass").on("click", function(){ genPass(); });
});

/*
 * Function to generate the value MD5 of the string gaven by user
 */
function getMd5(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'md5', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value MD5 of the string gaven by user
 */
function genMd5(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'genMd5', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value MD5 of the string gaven by user
 */
function genSha1(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'genSha1', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value MD5 of the string gaven by user
 */
function genPass(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'genPass', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value SHA1 of the string gaven by user
 */
function getSha1(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'sha1', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value Date in format Y-m-d H:i:s
 */
function getFut(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'fromunixtime', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value Date in format Y-m-d H:i:s
 */
function getFdt(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'fromdatetime', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value from Current Time
 */
function getCt(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'currentTime', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value from Current Date
 */
function getCd(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'currentDate', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value coded in string base64
 */
function getCb64(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'codeBase64', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};

/*
 * Function to generate the value decoded of string base64
 */
function getDcb64(){
  var data = $("#data").val();
  $.ajax({
    method: "POST",
    url: "tools/core.php",
    data: { method: 'decodeBase64', data: data }
  })
    .done(function( msg ){
      $('#rs').text( msg );
    });
};



