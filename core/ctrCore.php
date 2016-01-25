<?php
/**
 * Created by PhpStorm.
 * User: root
 * Date: 20/01/16
 * Time: 06:54 AM
 */
class CtrCore{
  function __construct(){}
  public function getMD5( $str = '' ){
    $core = new CtrEncrypt();
    return $core->getMD5( $str );
  }
  public function getSha1( $str = '' ){
    $core = new CtrEncrypt();
    return $core->getSha1( $str );
  }
  public function genMD5(){
    $core = new CtrEncrypt();
    return $core->genMD5();
  }
  public function genSha1(){
    $core = new CtrEncrypt();
    return $core->genSha1();
  }
  public function genPass(){
    $core = new CtrPass();
    return $core->genPassword();
  }
  public function getCodeBase64( $str = '' ){
    $core = new CtrEncrypt();
    return $core->getCodeBase64( $str );
  }
  public function getDecodeBase64( $str = '' ){
    $core = new CtrEncrypt();
    return $core->getDecodeBase64( $str );
  }
  public function getTimeFromUNix( $str = '' ){
    $core = new CtrTime();
    return $core->getTimeFromUNix( $str );
  }
  public function getTimeFromDate( $str = '' ){
    $core = new CtrTime();
    return $core->getTimeFromDate( $str );
  }
  public function getCurrentTime(){
    $core = new CtrTime();
    return $core->getCurrentTime();
  }
  public function getCurrentDate(){
    $core = new CtrTime();
    return $core->getCurrentDate();
  }
}

class CtrEncrypt{
  function __construct(){}
  public function getMD5( $str = '' ){
    return md5( $str );
  }
  public function getSha1( $str = '' ){
    return sha1( $str );
  }
  public function genMD5(){
    $str = date('H:i:s') . ' :: ' . rand( 1, rand( 10, 50 ) );
    return 'MD5 => ' . md5( $str );
  }
  public function genSha1(){
    $str = date('H:i:s') . ' :: ' . rand( 1, rand( 10, 50 ) );
    return 'SHA1 => ' . sha1( $str );
  }
  public function getCodeBase64( $str = '' ){
    return 'Base64 Encode => ' . base64_encode( $str );
  }
  public function getDecodeBase64( $str = '' ){
    return 'Base64 Decode => ' . base64_decode( $str );
  }
}

class CtrTime{
  function __construct(){}
  public function getTimeFromUNix( $str = '' ){
    if( !empty( $str ) ){
      $str = date( 'Y-m-d H:i:s', $str );
    }else{
      $str = date( 'Y-m-d H:i:s' );
    }
    return 'Time From Unix => ' . $str;
  }
  public function getTimeFromDate( $str = '' ){
    if( !empty( $str ) ){
      $str = strtotime( $str );
    }
    return $str;
  }
  public function getCurrentTime(){
    $date = date( 'Y-m-d' );
    $time = date( 'H:i:s' );
    $str = $time . date( ' | T e c' ) . ' | strtotime => '. strtotime( $date . ' ' . $time );
    return 'Current Time => ' . $str;
  }
  public function getCurrentDate(){
    $date = date( 'Y-m-d' );
    $time = date( 'H:i:s' );
    $str = $date . date( ' | T e c' ) . ' | strtotime => '. strtotime( $date . ' ' . $time );
    return 'Current Date => ' . $str;
  }
}

class CtrPass{
  function __construct(){}
  public function genPassword( $totalCharacters = 11, $totalSpecialCharacters = 2, $special = TRUE, $upper = TRUE, $numbers = TRUE ){
    $letter = '';
    for($i=0; $i<$totalCharacters; $i++){
      $letter[$i] = chr(rand(64,90));
      if($upper){
        $change = rand(1,10);
        if( $change > 5 ){
          $letter[$i] = strtoupper( $letter[$i] );
        }else{
          $letter[$i] = strtolower( $letter[$i] );
        }
      }
      if($numbers){
        $change = rand(0,1);
        if( $change == 1 ){
          $letter[$i] = rand(0,9);
        }
      }
    }
    if($special){
      $sc = $this->getSpecialCharacters();
      for($i=0; $i<$totalSpecialCharacters; $i++){
        $letter[ rand(0, ($totalCharacters-1)) ] = $sc[ rand( 0, (count( $sc )-1) ) ];
      }
    }
    return 'Password => ' . implode('', $letter);
  }
  public function getSpecialCharacters(){
    $data = array('!','@','#','$','/','+','|','_','&');
    return $data;
  }
}