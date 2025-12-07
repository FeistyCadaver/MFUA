DELETE FROM patient
WHERE mk_number NOT IN (SELECT DISTINCT patient_mk_number FROM appointment);