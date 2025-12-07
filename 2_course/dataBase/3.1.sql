UPDATE appointment
SET visit_cost = visit_cost * 1.15
FROM appointment a
INNER JOIN doctor d ON a.doctor_id = d.doctor_id
WHERE d.category = '1-я';