<?php
/**
 * Created by PhpStorm.
 * User: root
 * Date: 20/01/16
 * Time: 07:04 AM
 */
include('../core/ctrCore.php');

if( isset( $_POST['data'] ) && isset( $_POST['method'] ) ){
  $data = $_POST['data'];
  $method = $_POST['method'];

  $arrExceptions[] = 'genmd5';
  $arrExceptions[] = 'gensha1';
  $arrExceptions[] = 'currentTime';
  $arrExceptions[] = 'currentDate';

  //die('$method'.$method);

  switch( $method ){
    case 'md5':
      $data = getMd5( $data );
      break;
    case 'sha1':
      $data = getSha1( $data );
      break;
    case 'genMd5':
      $data = genMd5();
      break;
    case 'genSha1':
      $data = genSha1();
      break;
    case 'genPass':
      $data = genPass();
      break;
    case 'fromunixtime':
      $data = getFromunixtime( $data );
      break;
    case 'fromdatetime':
      $data = getFromdatetime( $data );
      break;
    case 'currentTime':
      $data = getCurrentTime();
      break;
    case 'currentDate':
      $data = getCurrentDate();
      break;
    case 'codeBase64':
      $data = getCodeBase64( $data );
      break;
    case 'decodeBase64':
      $data = getDecodeBase64( $data );
      break;
    default:
      $data = byDefault();
  }

  echo $data;
}

function byDefault(){
  $data = date('Y-m-d H:i:s');
  return 'NO DATA => ' . $data;
}

function getMd5( $data ){
  $core = new CtrCore();
  return $core->getMD5( $data );
}

function getSha1( $data ){
  $core = new CtrCore();
  return $core->getSha1( $data );
}

function genMd5(){
  $core = new CtrCore();
  return $core->genMD5();
}

function genSha1(){
  $core = new CtrCore();
  return $core->genSha1();
}

function genPass(){
  $core = new CtrCore();
  return $core->genPass();
}

function getFromunixtime( $data ){
  $core = new CtrCore();
  return $core->getTimeFromUnix( $data );
}

function getFromdatetime( $data ){
  $core = new CtrCore();
  return $core->getTimeFromDate( $data );
}

function getCurrentTime(){
  $core = new CtrCore();
  return $core->getCurrentTime();
}

function getCurrentDate(){
  $core = new CtrCore();
  return $core->getCurrentDate();
}

function getCodeBase64( $data ){
  $core = new CtrCore();
  return $core->getCodeBase64( $data );
}

function getDecodeBase64( $data ){
  $core = new CtrCore();
  return $core->getDecodeBase64( $data );
}
