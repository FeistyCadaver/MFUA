UPDATE appointment
SET visit_cost = visit_cost * 1.10
WHERE YEAR(session_date) = 2024;