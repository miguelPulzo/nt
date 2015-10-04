<?php
class IsOnline{
	var $social_site;
	var $cod_accept;

	//---------------
	public function __construct(){
		$this -> setVariables();
	}
	//---------------

	//---------------
	private function setVariables(){

		//SITIOS SOCIALES EMPLEADOS
		$this->social_site = array(
			//---
			'facebook' => array(
				'http://api.facebook.com/restserver.php?method=links.getStats&format=json&urls=www.pulzo.com',
/*
				'https://api.facebook.com',
				'https://developers.facebook.com',
				'https://connect.facebook.net/en/all.js',
*/
				'https://connect.facebook.net/es_LA/sdk.js#xfbml=1&version=v2.0',
			),
			//---
			'twitter' => array(
				'http://urls.api.twitter.com/1/urls/count.json?url=www.pulzo.com',
			),
			//---
			'g+' => array(
				'https://clients6.google.com/rpc',
			),
		);

		//CODES ACEPTADOS Y PERMITIDOS
		$this->cod_accept = array( '200','301','302' );
	}
	//---------------

	//---------------
	public function statusSite( $url = NULL ){
		$status = FALSE;

		if( !is_null( $url ) ){
			$content = get_headers($url);

			//if( empty( $content ) ) return FALSE;
			if( count( $content ) == 0 ) return FALSE;
			else{

				//$status_1 = 'HTTP/1.0 200 OK';
				foreach( $this->cod_accept AS $code ){
					$pos = strpos( $content[0], $code );

			    $status = FALSE;
				  if($pos !== FALSE)
				    return TRUE;
				  else
				  	$status = FALSE;
				}

			}
		}

		return $status;
	}
	//---------------

	//---------------
	// @social_network 	: 	Variable, índice del array de Social Sites ($this->social_site). Ej: 'facebook'
	public function statusSocialSite( $social_network = NULL ){
		$status = FALSE;

		if( !is_null( $social_network ) ){

			foreach( $this->social_site[ $social_network ] AS $url ){
				$status = $this->statusSite($url);
				if( !$status )
					break;
			}

		}

		return $status;
	}
	//---------------


	//---------------
	public function statusAllSocialSite(){

		$status = FALSE;
	
		foreach( $this->social_site AS $key => $value ){
			$status = $this->statusSocialSite( $key );
			if( !$status )
				break;
		}

		return $status;
	}
	//---------------
}
