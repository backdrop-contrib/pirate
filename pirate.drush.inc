<?php

/**
 * Implements hook_drush_command().
 */
function pirate_drush_command() {
  $items = array();
  $items['yarr'] = array(
    'description' => dt('Toggle the Pirate filter, despite the date'),
    'arguments'   => array(
      'on'    => dt('Turn the Pirate filter on, regardless of date'),
      'off'    => dt('Turn the Pirate filter off (this has no effect on September 19th)'),
    ),
    'examples' => array(
      'Standard example' => 'drush yarr',
      'Argument example' => 'drush yarr on',
    ),
    'aliases' => array('arrrrrrrrrr'),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function pirate_drush_help($command) {
  switch ($command) {
    case 'drush:my-command':
      return dt('Run my command');
  }
}

/**
 * Callback function for drush yarr.
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters converted to "_" characters (my_command)
 *
 * @param $arg1
 *   An optional argument
 */
function drush_pirate_yarr($arg1 = NULL) {
  //check if the argument was passed in and set the variable accordingly
  if (isset($arg1)) {
    switch ($arg1) {
      case 'on':
        variable_set('pirate_override', 1);
        drush_log('The Pirate filter override is now on.', 'ok');
        break;
      case 'off':
        variable_set('pirate_override', 0);
        drush_log('The Pirate filter override is now off.', 'ok');
        break;
    }
  }
  else {
    // toggle the override
    $override_status = !variable_get('pirate_override', 0);
    variable_set('pirate_override', $override_status);
    $override_drush_log = $override_status ? 'The Pirate filter override is now on.' : 'The Pirate filter override is now off.';
    drush_log($override_drush_log, 'ok');
  }
  cache_clear_all();
}