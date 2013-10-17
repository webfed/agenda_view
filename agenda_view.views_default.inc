<?php
/**
 * @file
 * agenda_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agenda_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Toepassen';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['pager_position'] = 'bottom';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['wrapper_class'] = 'agenda-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Veld: Inhoud: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['label'] = '';
  $handler->display->display_options['fields']['field_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datum']['alter']['text'] = 'j';
  $handler->display->display_options['fields']['field_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_datum']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Veld: Inhoud: Datum */
  $handler->display->display_options['fields']['field_datum_1']['id'] = 'field_datum_1';
  $handler->display->display_options['fields']['field_datum_1']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum_1']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum_1']['label'] = '';
  $handler->display->display_options['fields']['field_datum_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_datum_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Sort criterion: Inhoud: Datum (field_datum) */
  $handler->display->display_options['sorts']['field_datum_value']['id'] = 'field_datum_value';
  $handler->display->display_options['sorts']['field_datum_value']['table'] = 'field_data_field_datum';
  $handler->display->display_options['sorts']['field_datum_value']['field'] = 'field_datum_value';
  /* Filter criterion: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Inhoud: Datum (field_datum) */
  $handler->display->display_options['filters']['field_datum_value']['id'] = 'field_datum_value';
  $handler->display->display_options['filters']['field_datum_value']['table'] = 'field_data_field_datum';
  $handler->display->display_options['filters']['field_datum_value']['field'] = 'field_datum_value';
  $handler->display->display_options['filters']['field_datum_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_datum_value']['group'] = '0';
  $handler->display->display_options['filters']['field_datum_value']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Agenda list sidebar */
  $handler = $view->new_display('block', 'Agenda list sidebar', 'block_1');
  $handler->display->display_options['display_description'] = 'Agenda list sidebar';
  $translatables['events_list'] = array(
    t('Master'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('j'),
    t('Block'),
    t('more'),
    t('Agenda list sidebar'),
  );
  $export['events_list'] = $view;

  return $export;
}
