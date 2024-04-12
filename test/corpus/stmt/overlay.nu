=====
overlay-list-001-smoke-test
=====

overlay list

-----

(nu_script
  (overlay_list))

=====
overlay-hide-001-smoke-test
=====

overlay hide foo

-----

(nu_script
  (overlay_hide
    (cmd_identifier)))

=====
overlay-new-001-smoke-test
=====

overlay new foo

-----

(nu_script
  (overlay_new
    (cmd_identifier)))

=====
overlay-use-001-smoke-test
=====

overlay use foo

-----

(nu_script
  (overlay_use
    (identifier)))
