select distinct(A.car_id) from car_rental_company_car as A
inner join car_rental_company_rental_history as B
on A.car_id = B.car_id
where car_type = "세단" and start_date like "%-10-%"
order by car_id desc
