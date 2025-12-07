DELETE FROM diagnosis
WHERE diagnosis_id NOT IN (SELECT DISTINCT diagnosis_id FROM appointment WHERE diagnosis_id IS NOT NULL);