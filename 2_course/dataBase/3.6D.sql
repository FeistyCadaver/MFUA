DELETE FROM appointment
WHERE ticket_id NOT IN (SELECT valid_talon_id FROM talon_numbers);