# select A.rest_id, rest_name, food_type, favorites, address, round(avg(review_score), 2) as score 
# from rest_info A 
# inner join rest_review B on A.rest_id = B.rest_id 
# where address like "서울%" 
# order by score desc, favorites desc;

select A.rest_id, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, round(avg(review_score),2) as score
from rest_info as A
inner join rest_review as B on A.rest_id = B.rest_id
group by rest_id
having address like "서울%"
order by score desc, favorites desc;
