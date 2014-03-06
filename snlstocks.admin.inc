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
  $form['description']['#markup'] = '<p>Use the form below to test the results of
    an API Call to SNL. You can also use the <code>snlstocks_request()</code> function to
    retrieve the same results. See the README file for more information.</p>';
  $form['iid'] = array(
    '#type' => 'textfield',
    '#title' => t('Stock IID'),
    '#description' => t('Enter the IID of the stock.'),
    '#required' => TRUE,
    '#default_value' => 4098671,
  );
  $form['fndg'] = array(
    '#type' => 'textfield',
    '#title' => t('Stock FNDG'),
    '#description' => t('Enter the FNDG of the stock.'),
    '#required' => TRUE,
    '#default_value' => 214515,
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
  if (!is_numeric($form_state['values']['fndg'])) {
    form_error($form['fndg'], t('Stock FNDG must be numeric.'));
  }
}

/**
 * Submit function for admin form. Gets the results for the given IID.
 */
function snlstocks_test_form_submit($form, &$form_state) {
  $result = snlstocks_request($form_state['values']['iid'], $form_state['values']['fndg']);
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
    'title' => 'Stock Current Quote Results',
    'type' => 'ul',
  );

  return theme('item_list', $variables);
}

