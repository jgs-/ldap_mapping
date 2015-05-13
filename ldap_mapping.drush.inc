<?php
/* drush stuff */
function ldap_mapping_drush_help($command) {
        switch($command) {
                case 'drush:ldap-map':
                        return dt('ldap-map: update any field<->attribute mappings on a drupal user by connecting to LDAP');
        }   
}

function ldap_mapping_drush_command() {
        $items = array();
        $items['ldap-map'] = array(
                'description' => dt('Update the LDAP/Drupal mappings'),
                'arguments'   => array(
                        'ldap uid' => dt('uid attribute for LDAP user to search for'),
			'drupal user' => dt('drupal username to update'),
                ),  
		'examples'    => array(
			'Update a user' => dt('drush ldap-map s4229387 s4229387'),
			'Different usernames' => dt('drush ldap-map s4229387 x4229387')
		),
        );  

        return $items;
}

function drush_ldap_mapping_ldap_map($uid = NULL, $name = NULL) {
	if ($uid == NULL || $name == NULL) {
		drush_log('no user given', 'error');
		return;
	}

	do_mapping($uid, $name);
}
