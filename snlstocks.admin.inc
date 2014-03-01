<?php

/**
 * Callback function for the admin page.
 */
function snlstocks_admin() {
  return drupal_get_form('snlstocks_test_form');
}

/**
 * Builds the admin page form.
 */
function snlstocks_test_form($form, &$form_state) {
  $form['iid'] = array(
    '#type' => 'textfield',
    '#title' => t('Stock IID'),
    '#description' => t('Enter the IID of the stock.'),
    '#required' => TRUE,
    '#default_value' => 4098671,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Get Stock Details'),
  );

  return $form;
}

/**
 * Validate function for the admin form. Checks to make sure the given IID is
 * numeric.
 */
function snlstocks_test_form_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['iid'])) {
    form_error($form['iid'], t('Stock IID must be numeric.'));
  }
}

/**
 * Submit function for admin form. Gets the results for the given IID.
 */
function snlstocks_test_form_submit($form, &$form_state) {
  $result = snlstocks_request($form_state['values']['iid']);
  drupal_set_message(_snlstocks_html_format_results($result));
}

/**
 * Format the results into an UL suitable for `drupal_set_message()`.
 */
function _snlstocks_html_format_results($results_object) {
  $items = array();
  foreach ($results_object as $key => $value) {
    if (is_string($value)) {
      $items[] = '<strong>' . $key . ':</strong> <em>' . $value . '</em>';
    }
  }
  $variables = array(
    'items' => $items,
    'title' => null,
    'type' => 'ul',
  );

  return theme('item_list', $variables);
}

