<?php

//Función que retorna el HTML de los Videos contenidos en un playlist específico. El id del Playlist lo contiene la Variable $PlayList.
function angel_plYoutube_getPlVideos( $PlayList = NULL ){
  $html = '';

  if( empty( $PlayList ) )
    $PlayList = 'LLi8e0iOVk1fEOogdfu4YgfA'; //PLAYLIST TRAILERS

  $startList = 1;
  $endList = 100;
  $List = '&start-index='.$startList.'&amp;max-results='.$endList;
  $cont = json_decode(file_get_contents('http://gdata.youtube.com/feeds/api/playlists/'.$PlayList.'/?v=2&alt=json'.$List));
  $feed = $cont->feed->entry;

  if( count($feed) ){
    $i = 1;

    //$img_loading = drupal_get_path('module', 'lazyloader').'/loader/loader-1.gif';
    
    foreach($feed AS $item){
      //$media_title = strtolower($item -> title -> {'$t'});
      $media_title      = substr($item -> title -> {'$t'},0,70).'...';
      $media_published  = strtolower($item -> published -> {'$t'});
      $media_seialVideo = $item -> {'media$group'} -> {'yt$videoid'} -> {'$t'};
      $media_thumbnail  = $item -> {'media$group'} -> {'media$thumbnail'};
      $media_thumbnail  = $media_thumbnail[1];
      $media_url        = $media_thumbnail -> url;
      $media_height     = $media_thumbnail -> height;
      $media_width      = $media_thumbnail -> width;
      $media_link = 'http://www.youtube.com/embed/'.$media_seialVideo.'?rel=0&autoplay=1';
      $image_mu = '<img src="'.$media_url.'" />';

      //----------
      $link_video = l( $media_title, $media_link, array( 'attributes' => array( 'rel' => 'lightframe', 'title' => $media_title ) ) );
      $link_image = l( $image_mu, $media_link, array( 'attributes' => array( 'rel' => 'lightframe', 'title' => $media_title ), 'html' => TRUE ) );
      //----------
      $classname = '';
      //if( $i == 1 ) $classname = 'article-principal';

      $html .=  '
            <article class="'.$classname.'">
              <figure>'.$link_image.'</figure>
              <h2>'.$link_video.'</h2>
            </article>
          ';
      
      if( ($i%21)==0 )
        break;

      $i++;
    }
  }
  return $html;
}

//Funcion que retorna el HTML para un ID de video específico. El id esta contenido en la Variable $video.
function angel_plYoutube_getVideo( $video = NULL ){
  $html = '';

  if( empty( $video ) )
    return $html;

  $cont = json_decode(file_get_contents('http://gdata.youtube.com/feeds/api/videos/'.$video.'?v=2&alt=json'));
  $item = $cont->entry;

  //$media_title = strtolower($item -> title -> {'$t'});
  $media_title      = substr($item -> title -> {'$t'},0,70) . '...';
  $media_published  = strtolower($item -> published -> {'$t'});
  $media_seialVideo = $item -> {'media$group'} -> {'yt$videoid'} -> {'$t'};
  $media_thumbnail  = $item -> {'media$group'} -> {'media$thumbnail'};
  $media_thumbnail  = $media_thumbnail[1];
  $media_url        = $media_thumbnail -> url;
  $media_height     = $media_thumbnail -> height;
  $media_width      = $media_thumbnail -> width;
  $media_link       = 'http://www.youtube.com/embed/'.$media_seialVideo.'?rel=0&autoplay=1';
  $image_mu         = '<img src="'.$media_url.'" />';

  //----------
  $link_video = l( $media_title, $media_link, array( 'attributes' => array( 'rel' => 'lightframe', 'title' => $media_title ) ) );
  $link_image = l( $image_mu, $media_link, array( 'attributes' => array( 'rel' => 'lightframe', 'title' => $media_title ), 'html' => TRUE ) );
  //----------
  $classname = '';

  $html =  '
        <article class="'.$classname.'">
          <figure>'.$link_image.'</figure>
          <h2>'.$link_video.'</h2>
        </article>
      ';

  return $html;
}

//Funcion que retorna el HTML para el set de videos subidos por un usuario específio. El id esta contenido en la Variable $user.
function angel_plYoutube_getVideosUser( $user = NULL ){
  $html = '';
  $maxResults = 23;

  if( empty( $user ) )
    return $html;

  $cont = json_decode(file_get_contents('http://gdata.youtube.com/feeds/api/videos?author='.$user.'&max-results='.$maxResults.'&orderby=published&v=2&alt=jsonc'));
  $feed = $cont->data->items;
  
  $i = 1;
  foreach( $feed AS $item ){
    if( $i > 2){
      $media_title      = substr($item -> title,0,70).'...';
      $media_link       = 'http://www.youtube.com/embed/'.$item -> id.'?rel=0&autoplay=1';
      $media_url        = 'http://i.ytimg.com/vi/'.$item -> id.'/mqdefault.jpg';
      $image_mu         = '<img src="'.$media_url.'" />';

      //----------
      $link_video = l( $media_title, $media_link, array( 'attributes' => array( 'rel' => 'lightframe', 'title' => $media_title ) ) );
      $link_image = l( $image_mu, $media_link, array( 'attributes' => array( 'rel' => 'lightframe', 'title' => $media_title ), 'html' => TRUE ) );
      //----------

      $html .=  '
            <article class="'.$classname.'">
              <figure>'.$link_image.'</figure>
              <h2>'.$link_video.'</h2>
            </article>
          ';
    }
    $i++;
  }

  return $html;
}


//Función que retorna el array de los diferentes playlist que se desean para armar los bloques respectivos automáticamente.
function ap_getListPlaylist(){
  $playlists = array();

  $playlists = array(
    'trailers' => array( 
      'blockName'   => 'plYoutube',
      'playlistKey' => 'PLScC8g4bqD47c-qHlsfhGH3j6Bg7jzFy-'
    ),
    'music' => array( 
      'blockName'   => 'plYoutubeMusic',
      'playlistKey' => 'PLDcnymzs18LVXfO_x0Ei0R24qDbVtyy66' 
    ),
    'music_1' => array( 
      'blockName'   => 'plYoutubeMusic_1',
      'playlistKey' => 'PLh6vppUwmWEMdp04u-tYABoDmgn9AX12n'
    ),
    'billboar2015' => array( 
      'blockName'   => 'plYoutubeBillboar2015',
      'playlistKey' => 'PL55713C70BA91BD6E'
    ),
    'songsMoreViews' => array( 
      'blockName'   => 'plYoutubesongsMoreViews',
      'playlistKey' => 'PL15B1E77BB5708555'
    ),
    'funAnimals_1' => array( 
      'blockName'   => 'plYoutubefunAnimals_1',
      'playlistKey' => 'PLtDp75hOzOlapkvHlvm1Mo5vis4v_1kxF'
    ),
    'funAnimals_2' => array( 
      'blockName'   => 'plYoutubefunAnimals_2',
      'playlistKey' => 'PLtDp75hOzOlYjlJG8tCx-PThIo1XW7rM7'
    ),
    'funAnimals_3' => array( 
      'blockName'   => 'plYoutubefunAnimals_3',
      'playlistKey' => 'PLtDp75hOzOlbZoMYksF_1X7kSQl_gPatt'
    ),
    'estrenos2015' => array( 
      'blockName'   => 'estrenos2015',
      'playlistKey' => 'PLgPtEAlwxgkm03THHZS6plg5G3tHoaj-d'
    ),
    'estrenosEnero2015' => array( 
      'blockName'   => 'estrenosEnero2015',
      'playlistKey' => 'PLgPtEAlwxgkmypkZWQbEgiZktELQQkRTu'
    ),
    'estrenosFebrero2015' => array( 
      'blockName'   => 'estrenosFebrero2015',
      'playlistKey' => 'PLgPtEAlwxgkluglxYE8zZKW18MuV-Zgw2'
    ),
    'estrenosMarzo2015' => array( 
      'blockName'   => 'estrenosMarzo2015',
      'playlistKey' => 'PLgPtEAlwxgkmWxiDeO8tcDL6awZb0gxgo'
    ),
    'estrenosAbril2015' => array( 
      'blockName'   => 'estrenosAbril2015',
      'playlistKey' => 'PLgPtEAlwxgkm0g0xi9CPER-CJj3DQvRHU'
    ),

  );

  return $playlists;
}

function ap_getListUsers(){
  $users = array();

  $users[] = 'ForgetYourSadness';
  $users[] = '';
  $users[] = '';
  $users[] = '';
  $users[] = '';
  $users[] = '';

  return $users;
}

function ap_getListVideos(){
  $users = array();

  $users[] = '_vx1OVLX5Rc';
  $users[] = 'Kdft2G6em_M';
  $users[] = 'YB2WHOtmSHQ';
  $users[] = 'mccaQooi5rE';
  $users[] = 'RKBcs9tNWg8';
  $users[] = 'ilMzs1UHEmw';
  $users[] = 'u5dT8Pm9ow4';
  $users[] = '_U8GCrvHMzo';
  $users[] = '5dbvr7llFMo';
  $users[] = 'wozTHxykDwQ';
  $users[] = 'Ll0dalvIIco';
  $users[] = '-OMnm0x_yAM';
  $users[] = 'tauAUpOoEm0';
  $users[] = 'CswXANTpH4o';
  $users[] = 'RvklO0O3BcY';
  $users[] = 'Bn09g1bwgDc';
  $users[] = 'BTka0cgf99c';
  $users[] = '40DykbPa4Lc';
  $users[] = 'po0jY4WvCIc';
  $users[] = '2LgIj4xm4k0';
  $users[] = 'tntOCGkgt98';
  $users[] = 'IvdYyil6IEk';
  $users[] = 'YDdueeBf7MY';
  $users[] = 'QfVpXykZG5c';
  $users[] = 'WlRxNSRA7Rg';
  $users[] = 'guZav-VrJW0';
  $users[] = '4tzhyfWHdLo';
  $users[] = 'o5eaK9qlsFw';
  $users[] = 'Kdft2G6em_M';
  $users[] = 'FAcMeXVkC0Y';
  $users[] = '5dNBeLcg7OA';
  $users[] = 'JV8JPZyJiuE';

  return $users;
}
