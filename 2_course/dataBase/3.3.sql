UPDATE appointment
SET diagnosis_id = (SELECT diagnosis_id FROM diagnosis WHERE d_name = 'ОРВИ')
WHERE purpose_visit = 'Консультация'
    AND diagnosis_id IS NULL;