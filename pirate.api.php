<?php
// $Id$

/**
 * @file
 * Hooks provided by the Pirate filter module
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow other modules to add their own patterns for replacement
 *
 * @param $patterns
 *   An associative array of patterns, with the key as the search
 *   pattern and the value as the replacement pattern.
 */
function hook_captain(&$patterns) {
  $my_patterns = array(
    '%\bDrupal\b%'    => 'tha Drrupal',
    '%\bcommunity\b%' => 'curmmunity',
    '%\bplumbing\b%'  => 'depths',
  );
}

/**
 * @} End of "addtogroup hooks".
 */