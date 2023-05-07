=====
expr-001-smoke-test
=====

420 + 69

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_number)
        (val_number)))))

====
expr-002-preceedence
====

420 + 69 * 9001

----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_number)
        (expr_binary
          (val_number)
          (val_number))))))
