LDAP Mapping

This module takes attributes from an LDAP server (in our case, the
central LDAP service run by ITS) and maps them to corresponding fields
on a user's Drupal account. It includes a drush extension that let's us
do it from the command line.

After putting the module into your modules directory, you should be able
to configure it from the drupal modules config page.

drush can be used to create test users for ourselves, like so:

drush user-create x4229387 --mail="s4229387@student.uni.edu.au" --pass="omg"
drush ldap-map s4229387 x4229387

Then you can login to that account by going to /user and using x4229387 and 
the password 'omg'

Notice the account we created is 'x4229387', but we can specify which LDAP 
account to pull attributes from in the ldap-map command. The first argument
is always the LDAP account.
