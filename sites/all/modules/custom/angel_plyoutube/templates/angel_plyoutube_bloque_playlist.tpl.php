<?php
	drupal_add_css( drupal_get_path('module', 'angel_plyoutube').'/css/ag_plyoutube.css', array('group' => CSS_DEFAULT, 'type' => 'file') );
?>
<section id="youtube">
	<?php echo $nodes; ?>
</section>
