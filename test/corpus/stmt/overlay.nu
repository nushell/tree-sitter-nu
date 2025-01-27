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
    (unquoted)))

=====
overlay-hide-002-flags
=====

overlay hide --keep-env [PWD] foo
overlay hide foo --keep-custom

-----

(nu_script
  (overlay_hide
    (long_flag
      (long_flag_identifier))
    (val_list
      (list_body
        (val_entry
          (val_string))))
    (unquoted))
  (overlay_hide
    (unquoted)
    (long_flag
      (long_flag_identifier))))

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
    (unquoted)))

=====
overlay-use-002-flags
=====

overlay use foo.nu as "new name"
overlay use --prefix foo

-----

(nu_script
  (overlay_use
    (unquoted)
    (val_string))
  (overlay_use
    (long_flag
      (long_flag_identifier))
    (unquoted)))
