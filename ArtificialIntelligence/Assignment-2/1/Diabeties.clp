
(deffacts initial-phase
   (user start-program))

; *****
; RULES 
; *****

; RULE main-menu
; IF
;   The user chooses to start the program
; THEN
;   Ask the user to select what they want to do, and
;   Get the user's response

(defrule main-menu
(user start-program)
=>
(printout t crlf crlf crlf
"Welcome to a Medical Advisor System. " crlf crlf
"Main Menu:" crlf 
"1. Medical Advisor System" crlf 
"2. Diabetes Information" crlf 
"3. Exit the System" crlf
"Enter your selection: " )
(bind ?choice (read)) 
(while (and (neq ?choice 1)(neq ?choice 2)(neq ?choice 3))
(printout t "Invalid input, enter (1, 2 or 3): " ) 
(bind ?choice (read)))
(if (eq ?choice 1) then (assert (diabetes advisor)))
(if (eq ?choice 2) then (assert (diabetes information)))
(if (eq ?choice 3) then (assert (system exit))))

(defrule first-selection
   ?p <- (user start-program)
   ?c <- (diabetes advisor)
   =>
   (retract ?p ?c)
   (printout t  crlf crlf
    "This medical Advisor system is designed to give medical advice on diabetes."crlf
    "It advises the user on the following aspects: " crlf
    "1. Healthy eating plan" crlf
    "2. Healthy exercise program" crlf 
    "3. Monitoring blood sugar levels" crlf 
    "4. Maintaining a healthy weight" crlf
    "5. Education on diabetes" crlf
    "Please note this system is not a diabetes diagnosis tool." crlf crlf)
    (assert (tested-for diabetes)))

(defrule tested-diabetes
	(tested-for diabetes)
=>
( printout t crlf 
"Tips:" crlf 
"Diabetes is a serious condition where your blood sugar level is very high." crlf 
"This condition happens becuase your body cannot use up the sugar in your body." crlf 
"This sugar comes from the food we eat." crlf 
"Thus keeps the blood levels within the normal range." crlf crlf
"Have you tested for diabetes? (y/n): ")
( bind ?diabetic (read t))
(while (and (neq ?diabetic Y)(neq ?diabetic y)(neq ?diabetic N)(neq ?diabetic n)(neq ?diabetic Q)(neq ?diabetic q)) 
(printout t "Invalid input, please with a yes or no (y/n)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?diabetic (read))) 
(if (or (eq ?diabetic Q)(eq ?diabetic q)) then (halt))
( if ( eq ?diabetic n) then (assert (system exit))(diabetes-symptoms)(seen-doctor))
( if ( eq ?diabetic y) then ( assert ( diabetic has-tested))))

(deffunction diabetes-symptoms () " valid input is 1 2 3 4 5 6"
( printout t 
"Tips: " crlf 
"Common warning signs  of diabetes include the ones listed below, these warning" crlf 
"signs may occur suddenly. Note that these symptoms vary with individuals." crlf crlf 
"Which on of the following symptoms are you experiencing:" crlf
"1. Feeling very, very thirsty" crlf 
"2. Going to the toilet often" crlf 
"3. Losing weight even though you eating well" crlf 
"4. Always feeling hungry" crlf
"5. Feeling fatigue" crlf
"6. Not seeing well" crlf 
"7. No symptoms" crlf 
"Enter your choice, press enter: ") 
(bind ?choice (read)) 
(while (and (neq ?choice 1)(neq ?choice 2)(neq ?choice 3)(neq ?choice 4)(neq ?choice 5)(neq ?choice 6)(neq ?choice 7))
(printout t "Entered input is invalid, please enter your choice again: " ) 
(bind ?choice (read))) 
(if (eq ?choice 1) then ( assert (symptoms is-thirst)))
(if (eq ?choice 2) then ( assert (symptoms is-urination)))
(if (eq ?choice 3) then ( assert (symptoms is-weight)))
(if (eq ?choice 4) then ( assert (symptoms is-hunger)))
(if (eq ?choice 5) then ( assert (symptoms is-fatigue)))
(if (eq ?choice 6) then ( assert (symptoms is-vision)))
(if (eq ?choice 7) then ( assert (symptoms no-symptoms)) (printout t crlf 
"Medical Advice:" crlf crlf
"Diabetes mellitus is a clinical syndrome characterized by high blood sugar levels,  due to absolute deficiency of insulin." crlf
"The lack of insulin affects the metabolism of the body.  If you experience any of the aforementioned symptoms, go to " crlf
"the clinic immediately." crlf  crlf
"Thank you for using the system. Goodbye!" crlf crlf) (exit()))

(printout t "Are you experiencing other symptoms? (y/n): ")
(bind ?choice (read)) 
(if (eq ?choice n) then
(if (eq ?choice 1) then ( assert (symptoms is-thirst)))
(if (eq ?choice 2) then ( assert (symptoms is-urination)))
(if (eq ?choice 3) then ( assert (symptoms is-weight)))
(if (eq ?choice 4) then ( assert (symptoms is-hunger)))
(if (eq ?choice 5) then ( assert (symptoms is-fatigue)))
(if (eq ?choice 6) then ( assert (symptoms is-vision)))
(if (eq ?choice 7) then ( assert (symptoms no-symptoms))))

(if (eq ?choice y) then
(while(neq ?choice 0)
( printout t 
"Which on of the following symptoms are you experiencing:" crlf
"1. Feeling very, very thirsty" crlf 
"2. Going to the toilet often" crlf 
"3. Losing weight even though you eating well" crlf 
"4. Always feeling hungry" crlf
"5. Feeling fatigue" crlf
"6. Not seeing well" crlf 
"0. If you have no other symptoms" crlf 
"Enter your choice, press enter: ")  
(bind ?choice (read)) 
(while (and (neq ?choice 1)(neq ?choice 2)(neq ?choice 3)(neq ?choice 4)(neq ?choice 5)(neq ?choice 6)(neq ?choice 0))
(printout t "Entered input is invalid, please enter your choice again: " ) 
(bind ?choice (read)))
(if (eq ?choice 1) then ( assert (symptoms is-thirst)))
(if (eq ?choice 2) then ( assert (symptoms is-urination)))
(if (eq ?choice 3) then ( assert (symptoms is-weight)))
(if (eq ?choice 4) then ( assert (symptoms is-hunger)))
(if (eq ?choice 5) then ( assert (symptoms is-fatigue)))
(if (eq ?choice 6) then ( assert (symptoms is-vision))))
(assert (doctor visit))))

(defrule diabetic-patient
	(diabetic has-tested)
=>
( printout t "Do you have diabetes? (y/n): ")
( bind ?diabetic (read))
(while (and (neq ?diabetic Y)(neq ?diabetic y)(neq ?diabetic N)(neq ?diabetic n)(neq ?diabetic Q)(neq ?diabetic q)) 
(printout t "Invalid input, please with a yes or no (y/n)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?diabetic (read))) 
(if (or (eq ?diabetic Q)(eq ?diabetic q)) then (halt))
(if (eq ?diabetic y) then
( printout t crlf
"Tips:" crlf 
 "Diabetes has two types: Type 1 and Type 2." crlf 
"Type 1 is common to people under the age of 30. People with type 1 do not produce insulin." crlf 
"Type 2 runs in the family and is common to people older than 40. " crlf 
"But all these types depends on individuals. " crlf crlf 
"What type of diabetes have you been diagnosed with? " crlf
"1 = type I" crlf
"2 = type II" crlf
"3 = If you dont know" crlf
"Enter number: ")
( bind ?diabetic-type(read t))
(while (and (neq ?diabetic-type 3)(neq ?diabetic-type 1)(neq ?diabetic-type 2)(neq ?diabetic-type Q)(neq ?diabetic-type q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1,2 or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?diabetic-type (read))) 
(if (or (eq ?diabetic-type Q)(eq ?diabetic-type q)) then (halt))
( if ( eq ?diabetic-type 1) then ( assert ( diabetic-type has-type-1)))
( if ( eq ?diabetic-type 2) then ( assert ( diabetic-type has-type-2)))
( if ( eq ?diabetic-type 3) then ( assert ( diabetic-type has-no-clue)))
(diabetic-medication)(eating-plan)(exercise-plan)
(sugar-monitor)(alcohol-consumption)(check-smoking)
(assert  (diabetes advice)))
(if (eq ?diabetic n) then (assert ( diabetic no-diabetes))))

(deffunction seen-doctor ()
(printout t crlf )
(printout t "Have you seen a doctor for your symptoms? (y/n): ")
(bind ?doctor (read))
(while (and (neq ?doctor Y)(neq ?doctor y)(neq ?doctor N)(neq ?doctor n)(neq ?doctor Q)(neq ?doctor q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a yes or no (y/n)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?doctor (read))) 
(if (or (eq ?doctor Q)(eq ?doctor q)) then (halt))
( if ( eq ?doctor y) then (assert (doctor has-seen-a-doctor)))
( if ( eq ?doctor n) then (assert (doctor has-not-seen-a-doctor))(assert  (diabetes advices)))
)

(defrule advices
(diabetes advices)
=>
(printout t crlf crlf
"Medical Advisor:" crlf ))

(defrule seen-a-doctor
(doctor has-seen-a-doctor)
=>
(eating-plan)(exercise-plan)(assert  (diabetes advices)) )

(defrule not-seen-a-doctor
(doctor has-not-seen-a-doctor)
=>
(printout t crlf 
"It is recommended that you go see a doctor or nurse." crlf))

(defrule thirsty-sym
(symptoms is-thirst)
=>	
(printout t crlf
"Excess thirsty results from the excess glucose in the body, because water is being" crlf
"drawn from you body tissues. This includes dehydration from frequent urination," crlf 
"thus causing you to drink more water or other fluids to quench your thirst."crlf  
"" crlf))

(defrule urination-sym
(symptoms is-urination)
=>
(printout t crlf
"Urination becomes more frequent when there is excess glucose in the blood. " crlf
"For people with diabetes the excess glucose in the blood builds up, therefore " crlf 
"the kidneys are forced to work overtime to filter and absorb the excess sugar. " crlf 
"When the kidney cannot keep up, this normally results in frequent urination." crlf
"" crlf))

(defrule hunger-sym
(symptoms is-hunger)
=>
(printout t 
"Increased hunger can be caused by the excess of glucose in your body, causing an increased " crlf
"in apettite. "crlf 
"" crlf)) 

(defrule weight-sym
(symptoms is-weight)
=>
(printout t crlf
"Sudden unexplained weight loss can results from the unability of the body cells to use up" crlf
"the sugar in the body. This can also results in frequent urination, causing you to loss" crlf 
"calories. Because the body can not break the food into energy and fat, cause weigh loss. " crlf 
"" crlf)) 

(defrule fatigue-sym
(symptoms is-fatigue)
=>
(printout t crlf
"Feeling fatigued, can results from dehydration from frequent urination since your body " crlf 
"is unable to use up the sugar needed for energy." crlf 
"" crlf)) 

(defrule vision-sym
(symptoms is-vision)
=>
(printout t crlf
"Blurred vision occurs when the high levels of glucose in the blood causes water from "crlf 
"the lens to go outward and deforming the lens, making the vision unfocused. " crlf 
"" crlf)) 

(defrule patient-is-diabetic
(diabetic no-diabetes)
=>
(diabetes-symptoms)(seen-doctor)
(assert (system exit)))

(deffunction exercise-plan () "comment"
(printout t crlf
"Tips:"crlf 
"Exercise  is important  as it  improves blood sugar control  and  reduces"crlf 
"risk of developing heart and blood vessel disease and high blood pressure."crlf 
"Being overweight makes it more difficult for ones body to use insulin properly," crlf 
"this can make your blood sugar to get too high." crlf crlf
"Do you exercise? (y/n): ")
(bind ?plan (read t))
(if (eq ?plan y) then (assert (plan has-no-exercise-plan)))
(if (eq ?plan y) then 
(printout t crlf 
"How often do you exercise? " crlf
"1 = once per week" crlf
"2 = two times a week" crlf
"3 = three times a week" crlf
"4 = four times a week" crlf
"5 = Daily" crlf
"Enter number: ")
(bind ?time (read t))
(while (and (neq ?time 1)(neq ?time 2)(neq ?time 3)(neq ?time Q)(neq ?time q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?time (read))) 
(if (or (eq ?time Q)(eq ?time q)) then (halt))
(if (eq ?time  1) then ( assert (time  bad)))
(if (eq ?time  2) then ( assert (time  bad)))
(if (eq ?time  3) then ( assert (time  good)))
(if (eq ?time  4) then ( assert (time  good)))
(if (eq ?time  5) then ( assert (time  good)))
(printout t crlf )
(printout t "Are your exercises less than 30 minutes? (y/n): ")
(bind ?duration (read t))
(while (and (neq ?duration Y)(neq ?duration y)(neq ?duration N)(neq ?duration n)(neq ?duration Q)(neq ?duration q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a yes or no (y/n)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?duration (read))) 
(if (or (eq ?duration Q)(eq ?duration q)) then (halt))
(if (eq ?duration n) then ( assert (duration bad)))
(if (eq ?duration y) then ( assert (duration good)))
))

(deffunction alcohol-consumption () "comment"
(printout t crlf )
(printout t "Do you drink alcohol? (y/n): ")
(bind ?drink (read t))
(if (eq ?drink y) then 
(printout t "Tips: " crlf
"Alcohol is not out of bound to people with diabetes," crlf 
"as long as one is careful. Most alcoholic drinks contain" crlf
"simple sugars which can increase the risk of hypoglycemia"crlf
"or low blood sugar if one drinks on an empty stomach." crlf crlf)
( assert (drink alcoholic)))
(if (eq ?drink n) then (assert(drink non-alcoholic)))
)

(deffunction check-smoking () "comment"
(printout t crlf )
(printout t "Do you smoke? (y/n): ")
(bind ?smoke (read t))
(if (eq ?smoke y) then 
(printout t 
"Tips: " crlf
"Smoking increases your risk of having a heart attack or" crlf
"stroke. It can also doubles the risk of other illnesses." crlf)
( assert (smoke smoker)))
(if (eq ?smoke n) then ( assert (smoke non-smoker)))
)

(deffunction sugar-monitor() "valid input y or n"
(printout t crlf )
(printout t "TIPS:" crlf )
(printout t "It is important to monitor you blood sugar level, and you can monitor it" crlf )
(printout t "by measuring the glucose in your blood. Please note that you cannot use urine " crlf )
(printout t "to test for the presence of sugar in your blood. It is no longer recommended" crlf )
(printout t "as a method for measuring your blood glucose. However, you can use a your blood." crlf )
(printout t "Look at devices such as Accu-check to get the value of your blood glucose." crlf crlf)
(printout t "Do you monitor your blood sugar level? (y/n): " )
(bind ?monitor(read t))
(if ( eq ?monitor y) then
(printout t crlf )
(printout t "How often do you monitor your blood glucose level?" crlf )
(printout t "1 = 4 times daily" crlf)
(printout t "2 = 2 times daily" crlf)
(printout t "3 = once daily" crlf)
(printout t "4 = weekly" crlf)
(printout t "Enter number: ")
(bind ?monitor-t (read t))
(while (and (neq ?monitor-t 1)(neq ?monitor-t 2)(neq ?monitor-t 3)(neq ?monitor-t Q)(neq ?monitor-t q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, 3 or 4)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?monitor-t (read))) 
(if (or (eq ?monitor-t Q)(eq ?monitor-t q)) then (halt))
(if (eq ?monitor-t 1) then ( assert (monitor-t monitor-good)))
(if (eq ?monitor-t 2) then ( assert (monitor-t monitor-bad)))
(if (eq ?monitor-t 3) then ( assert (monitor-t monitor-bad)))
(if (eq ?monitor-t 4) then ( assert (monitor-t monitor-bad)))

( printout t "Enter your recent blood glucose average" crlf )
(printout t "1 = < 6" crlf)
(printout t "2 = 6 - 6.9" crlf)
(printout t "3 = > 7" crlf)
(printout t "Enter number: ")
(bind ?monitor-n (read t))
(while (and (neq ?monitor-n 1)(neq ?monitor-n 2)(neq ?monitor-n 3)(neq ?monitor-n Q)(neq ?monitor-n q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2 or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?monitor-n (read)))
(if (or (eq ?monitor-n Q)(eq ?monitor-n q)) then (halt))
(if (eq ?monitor-n 1) then 
( printout t crlf )
( printout t 
"Tips:" crlf
"If your blood sugar drops very low (i.e. below 3.5 mmol/L) you may experience " crlf 
"Hypoglycaemia or low blood sugar reactions. " crlf  crlf crlf
"Does your blood sugar level ever get low? (y/n): " )
( bind ?blood(read t))
( if ( eq ?blood y) then ( assert ( low-blood yes )))
( if ( eq ?blood n) then ( assert ( low-blood no ))))
(if (eq ?monitor-n 2) then ( assert (monitor-n good)))
(if (eq ?monitor-n 3) then 
( printout t crlf )
( printout t 
"Tips:" crlf
"If your blood sugar is very high (i.e. above 10 mmol/L) you may experience " crlf 
"Hyperglycaemia or high blood sugar reactions. " crlf  crlf crlf
"Does your blood sugar level ever get higher? (y/n): " )
( bind ?blood(read t))
( if ( eq ?blood y) then ( assert ( high-blood yes )))
( if ( eq ?blood n) then ( assert ( high-blood no ))))
(if ( eq ?monitor n) then ( assert ( monitor no-monitor )))))

(deffunction eating-plan () "comment"
(printout t crlf )
(printout t "Tips:" crlf
"The best healthy food choices for people with diabetes are the same as those for everyone else." crlf
"There is no such thing as a 'diabetic plan',it is simply a healthy eating plan" crlf
"The aim of a healthy eating plam is to control the level of glucose in your blood." crlf
"Staying as healthy as possible can make a huge difference in your life" crlf
"Thus, it is important to control your blood ugar and to reduce risk of complications" crlf crlf)
(printout t "Do you have a healthy eating plan? (y/n): ")
(bind ?diet (read t))
(if (eq ?diet y) then ( assert (diet has-diet-plan)))
(if (eq ?diet n) then ( assert (diet has-no-diet-plan)))
(printout t crlf 
"How often do you eat high fibre food (such as rice,potatoes, corn, maize meal or bread)?" crlf
"1 = daily" crlf
"2 = more than 3 times a week" crlf
"3 = less than 3 times a week" crlf
"Enter number: ")
(bind ?high-fibre (read t))
(while (and (neq ?high-fibre 1)(neq ?high-fibre 2)(neq ?high-fibre 3)(neq ?high-fibre Q)(neq ?high-fibre q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?high-fibre (read))) 
(if (or (eq ?high-fibre Q)(eq ?high-fibre q)) then (halt))
(if (eq ?high-fibre 1) then ( assert (high-fibre daily)))
(if (eq ?high-fibre 2) then ( assert (high-fibre  more)))
(if (eq ?high-fibre 3) then ( assert (high-fibre  less)))

( printout t crlf 
"How often do you eat lower fat food (such as meat, fish or skinless chicken)?" crlf
"1 = dialy" crlf
"2 = more than 3 times a week" crlf
"3 = less than 3 times a week" crlf
"Enter number: ")
(bind ?low-fat-food (read t))
(while (and (neq ?low-fat-food 1)(neq ?low-fat-food 2)(neq ?low-fat-food 3)(neq ?low-fat-food 4)(neq ?low-fat-food Q)(neq ?low-fat-food q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?low-fat-food (read))) 
(if (or (eq ?low-fat-food Q)(eq ?low-fat-food q)) then (halt))
(if (eq ?low-fat-food 1) then ( assert (low-fat-food daily)))
(if (eq ?low-fat-food 2) then ( assert (low-fat-food  more)))
(if (eq ?low-fat-food 3) then ( assert (low-fat-food  less)))

( printout t crlf 
"How often do you eat sugary and fatty food (suc as simple sugars, oily foods, sweets, etc)?" crlf
"1 = dialy" crlf
"2 = more than 3 times a week" crlf
"3 = less than 3 times a week" crlf
"Enter number: ")
(bind ?fatty-food (read t))
(while (and (neq ?fatty-food 1)(neq ?fatty-food 2)(neq ?fatty-food 3)(neq ?fatty-food Q)(neq ?fatty-food q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?fatty-food (read))) 
(if (or (eq ?fatty-food Q)(eq ?fatty-food q)) then (halt))
(if (eq ?fatty-food 1) then ( assert (fatty-food daily)))
(if (eq ?fatty-food 2) then ( assert (fatty-food  more)))
(if (eq ?fatty-food 3) then ( assert (fatty-food  less)))

( printout t crlf 
"How often do you eat milky and dairy food (such as low fat milk, yoghurt, etc)?" crlf
"1 = dialy" crlf
"2 = more than 3 times a week" crlf
"3 = less than 3 times a week" crlf
"Enter number: ")
(bind ?milky-food (read t))
(while (and (neq ?milky-food 1)(neq ?milky-food 2)(neq ?milky-food 3)(neq ?milky-food Q)(neq ?milky-food q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?milky-food (read)) )
(if (or (eq ?milky-food Q)(eq ?milky-food q)) then (halt))
(if (eq ?milky-food 1) then ( assert (milky-food daily)))
(if (eq ?milky-food 2) then ( assert (milky-food  more)))
(if (eq ?milky-food 3) then ( assert (milky-food  less)))

( printout t crlf 
"How often do you eat fruits and vegetablesn(such as peas, apples, bananas, mangos, etc)? " crlf
"1 = dialy" crlf
"2 = more than 3 times a week" crlf
"3 = less than 3 times a week" crlf
"Enter number: ")
(bind ?fruit-and-veg (read t))
(while (and (neq ?fruit-and-veg 1)(neq ?fruit-and-veg 2)(neq ?fruit-and-veg 3)(neq ?fruit-and-veg Q)(neq ?fruit-and-veg q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?fruit-and-veg (read)) )
(if (or (eq ?fruit-and-veg Q)(eq ?fruit-and-veg q)) then (halt))
(if (eq ?fruit-and-veg 1) then ( assert (fruit-and-veg daily)))
(if (eq ?fruit-and-veg 2) then ( assert (fruit-and-veg  more)))
(if (eq ?fruit-and-veg 3) then ( assert (fruit-and-veg  less)))

( printout t crlf 
"How many meals do you have per day? " crlf
"1 = 1 meals (breakfast, lunch or dinner)" crlf
"2 = 2 meals (breakfast, lunch or dinner)" crlf
"3 = 3 meal (breakfast, lunch and dinner)" crlf
"Enter number: ")
(bind ?meals-times (read t))
(while (and (neq ?meals-times 1)(neq ?meals-times 2)(neq ?meals-times 3)(neq ?meals-times Q)(neq ?meals-times q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?meals-times (read))) 
(if (or (eq ?meals-times Q)(eq ?meals-times q)) then (halt))
(if (eq ?meals-times 1) then ( assert (meals-times normal)))
(if (eq ?meals-times 2) then ( assert (meals-times  good)))
(if (eq ?meals-times 3) then ( assert (meals-times  bad)))
)

( deffunction diabetic-medication() "valid input 1, 2 or 3"
( printout t crlf )
( printout t "Are you taking any diabetic medication? (y/n): " )
( bind ?medication(read t))
( if ( eq ?medication n) then 
(printout t crlf crlf
"Medication is not the only way to manage you diabetes. "crlf 
"Do not take diabetic medication unless instructed by a doctor or a nurse. "crlf
"Eating healthy, exercising regularly and losing weight may be all you need to manage your diabetes. "crlf 
"If your doctor did not tell you to take medication then it is best not to. " crlf crlf))
( if ( eq ?medication y) then 
(printout t crlf crlf
"ADVICE: Please remember to take your medication exactly as your doctor or nurse instructed." crlf
"You must take your medication at the same time every day, with meals. " crlf
"Do not stop taking your medical unless your doctor or nurse tells you to." crlf
"Always make sure that you have enough medication to last you until your next clinic visit." crlf crlf)
(assert (medication takes-meds))
(printout t crlf )
(printout t "What medication are you taking?" crlf)
(printout t "1 = oral medication" crlf)
(printout t "2 = insulin " crlf)
(printout t "3 = insulin and oral medication" crlf)
(printout t "Enter number: ")
(bind ?med-type (read t))
(while (and (neq ?med-type 3)(neq ?med-type 1)(neq ?med-type 2)(neq ?med-type Q)(neq ?med-type q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1,2 or 3)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?med-type (read))) 
(if (or (eq ?med-type Q)(eq ?med-type q)) then (halt))
(if (eq ?med-type 1) then ( assert (med-type oral)))
(if (eq ?med-type 2) then ( assert (med-type  insulin)))
(if (eq ?med-type 3) then ( assert (med-type  both)))

( printout t crlf )
( printout t "How many times per week do you forget to take your medication?" crlf )
(printout t "1 = never" crlf)
(printout t "2 = once per week" crlf)
(printout t "3 = twice a week" crlf)
(printout t "4 = more than three times a week" crlf)
(printout t "Enter number: ")
(bind ?med-forget (read t))
(while (and (neq ?med-forget 1)(neq ?med-forget 2)(neq ?med-forget 3)(neq ?med-forget 4)(neq ?med-forget Q)(neq ?med-forget q)) 
(printout t "You have entered wrong answer"crlf 
"Please with a (1, 2, 3 or 4)..." crlf 
"if you need to quit enter q...." crlf) 
(bind ?med-forget (read))) 
(if (or (eq ?med-forget Q)(eq ?med-forget q)) then (halt))
(if (eq ?med-forget 1) then ( assert (med-forget i-dont-forget)))
(if (eq ?med-forget 2) then ( assert (med-forget i-do-forget)))
(if (eq ?med-forget 3) then ( assert (med-forget i-do-forget)))
(if (eq ?med-forget 4) then ( assert (med-forget i-do-forget))))
( if ( eq ?medication n) then ( assert ( medication not-medication ))))


(defrule Has-Diabetes
    (diabetes advice)
=>
(printout t crlf crlf
"Medical Advice:" crlf crlf
"Now that you have diabetes your main aim is to bring your blood sugar back to an acceptable level." crlf  
"You must make sure that you manage your diabetes properly.Take note of every advice provided," crlf crlf))

;###################  EATING ADVICE ######################
(defrule eating-plans
(diet has-diet-plan)
=>
(printout t  crlf
"It is good that you have a healthy eating plan. Remember to eat your meals in
small portions, 3 meals a day with snacks in between you meals is advisable.
It is important that you have variety of this type of food every day. Drink a lot of
clean water as well." crlf crlf))

(defrule eating-plan
(diet has-no-diet-plan)
=>
(printout t  crlf
"Eat different types of food every day, do not eat alot of food at the same time." crlf 
"Eat healthy food choices, while you drink alot of clean and safe water" crlf
"Limit the following in your meals:" crlf
"1.sugar and sugary foods intake." crlf
"2. salt in your diet." crlf
"And include starchy food at each meals." crlf crlf)) 

(defrule high-fibre-food
(high-fibre daily|less|more)
=>
(printout t crlf 
"High fibre food: Eat 2 â€“ 3 portions of this type per meal." crlf
"Here are some recommendations you can eat:" crlf
"Breakfast: oats, bread, corn," crlf
"Lunch/Diner: sweet potatoes, potatoes, samp, maize meal, rice." crlf crlf)) 


(defrule low-fat-food
(high-fibre daily|less|more)
=>
(printout t  crlf
"Low fat: Eat 2 â€“ 3 portions of low fat food each day such as low fat milk, low fat
yoghurt, etc" crlf crlf)) 

(defrule fatty-food
(fatty-food daily|less|more)
=>
(printout t  crlf
"Fatty food: You must be very careful while eating fatty foods. Too much fat can" crlf
"make you put on weight. Remember cut off all fat meat and remove chicken skin" crlf
"before you prepare your meal. Avoid using oil while preparing your meal." crlf crlf)) 

(defrule milky-food-type
(milky-food daily|less|more)
=>
(printout t  crlf
"Milky and diary: Eat 2 - 3 portions of milky or protein food each day such as fat
free milk, eggs or low fat plain." crlf crlf))

(defrule fruit-and-veg-food
(fruit-and-veg daily|less|more)
=>
(printout t crlf
"Fruit and vegetables: Eat different types of fruit and vegetables every day. Eat 3 - 5" crlf
"portions each day to provide you with vitamins, minerals and fibre to help you to" crlf
"balance your overall diet. For fruits, a portion is: 1 banana, 1 mango, 1 apple..." crlf
"For vegetables a portion is: 1/2 cup of spinach, 1/2 cup of peas and 1/2 cup of" crlf
"mixed veg ..." crlf crlf)) 

(defrule meals-per-day
(meals-times good|bad)
=>
(printout t crlf 
"Eat three meals a day, also avoid skipping meals.Space your breakfast, " crlf 
"lunch and dinner over the day to help you manage your health." crlf crlf)) 

;###################  EXERCISE ADVICE ######################
(defrule planning
(plan has-no-exercise-plan)
=>
(printout t  crlf
"Exercise is good for you regardless, you must exercise more regularly to help  " crlf 
"your body to use up some the sugar in your blood. Keeping a good weight can help" crlf
"you to control your blood sugar thus reducing your risks of heart diseases." crlf)) 

(defrule bad-exercise
( time bad )
=>
(printout t  crlf
"Exercise plan: Bad exercise is bad for your diabetes. You must try to exercise" crlf
"more often. You can choose any exercise that you will enjoy as suggested during" crlf
"the consultation. Exercise daily for 30 â€“ 45 minutes at least." crlf crlf))

;###################  SUGAR MONITOR ADVICE ######################
(defrule sugar-monitor
( monitor no-monitor )
=>
(printout t  crlf
"It is important to monitor your blood sugar levels regularly." crlf 
"Make sure that you record your readings daily. " crlf
"It is recommended that you test your blood sugar levels four times a day." crlf))

;###################  DRINKING ADVICE ######################
(defrule alcoholic
(drink alcoholic)
=>
(printout t  crlf
"Drinking alcohol is not restricted for people with diabetes, but you must drink at
most 1 unit per day." crlf 
"Drink lots of clean water 8 - 9 glasses a day" crlf crlf)) 

;###################  SMOKING ADVICE ######################
(defrule smoking
(smoke smoker)
=>
(printout t  crlf
"Stop smoking, its not good for your health" crlf  crlf))

;###################  MEDICATION ADVICE ######################
(defrule medication
(medication takes-meds)
=>
(printout t  crlf
"Please remember to take your medication as your doctor or nurse tells you. You
must take your tablets the same time every day, with meals. Do not stop taking
your medication unless your doctor tells you to. Always make sure that you have
enough medication to last you until your next clinic visit. Remember that you must
not use the same place for injection every time because you medication can stop
working. You can change sides a place daily." crlf crlf))

(defrule medications
(medication not-medication)
=>
(printout t  crlf
"If your doctor or nurse never told you to take medication then it is better that you do
not. Diabetes medication is not the only way to manage your diabetes. There are other ways
such as eating healthy and exercising more often." crlf crlf))

;###################  DIABETES INFORMATION ######################
(defrule second-selection
 ?p <- (user start-program)
 ?c <- (diabetes information)
=>
(retract ?p ?c)
(printout t crlf crlf 
"Diabetes Information Menu: " crlf crlf
"1. What is diabetes?" crlf 
"2. What are the types of diabetes?" crlf 
"3. Diabetes causes" crlf 
"4. Diabetes symptoms" crlf
"5. Diabetes treatment" crlf 
"6. Diabetes prevention" crlf
"7. Diabetes medication" crlf 
"8. Diabetes complications" crlf
"9. Restart the system" crlf
"Enter your selection: " )
(bind ?choice (read)) 
(while (and (neq ?choice 1)(neq ?choice 2)(neq ?choice 3)(neq ?choice 4)(neq ?choice 5)(neq ?choice 6)(neq ?choice 7)(neq ?choice 8)(neq ?choice 9))
(printout t "Invalid input, enter (1, 2, 3, 4, 5,6,7,8 or 9): " ) 
(bind ?choice (read)))
(if (eq ?choice 1) then (printout t crlf crlf
"What is Diabetes?" crlf crlf
"Diabetes mellitus is a clinical syndrome characterized by high blood sugar levels,  due to absolute deficiency of insulin.The lack of insulin affects the metabolism of the body.  This causes an increase in the blood sugar levels because there is not enough insulin to reduce the percentage of glucose to its normal level.  Insulin is a hormone produced by the beta cells in  the pancreas, which helps to control the amount of glucose absorbed into the blood cells. In people with diabetes the beta cells either produce too little or no insulin." crlf  )
(assert (diabetes information)))
(if (eq ?choice 2) then (printout t crlf crlf
"What are the types of Diabetes?" crlf crlf
" There are two main types of diabetes, namely, Type 1 and Type 2." crlf
"Type 1 diabetes" crlf 
"Type I diabetes mellitus occurs when the beta cells in the pancreas are damaged. Therefore the pancreas does not produce insulin anymore. Type 1 normally occurs in people under the age of 30 but it can also occur in orlder people as well due to destruction of pancreas by alcohol, disease or removal by surgery or progressive failure of pancreatic beta cells which produce insulin." crlf crlf
"Type 2 diabetes" crlf
"Type 2 diabetes mellitus occurs when the beta cells in the body are resistant to the effect of insulin. It develops gradually over a period of time but normally runs in families with a history of diabetes. The treatment of this condition usually begins with changes in diet and exercise since it is frequently associated with obesity. Type 2 normally occurs in people older than 40 years of age." crlf crlf
"However, there are other types such as Pre-diabetes and Gestational diabetes." clrf crlf
"Pre-diabetes" crlf
"Pre-diabetes is the pre-cursor of diabetes where the blood glucose levels are higher than normal but not high enough to be considered as diabetes. However, if the condition is tackled at this stage through diet, exercise and other healthy lifestyle changes (weight management programme), the risk can be significantly reduced. " crlf crlf
"Gestational diabetes." crlf
"This type of diabetes affects about most females during last months of pregnancy. Gestational diabetes is normally associated with type II diabetes mellitus prevalence depending on the
population group studied. Studies have shown that women with Gestational diabetes mellitus are at risk of developing type II diabetes mellitus in the long term if the correct treatment is not practised at an early stage. Some women have very high levels of glucose in their blood, and their bodies are unable to produce enough insulin to transport all of the glucose into their cells, resulting in progressively rising levels of glucose. Pregnant women have enough insulin, but the effect of insulin is partially blocked by other hormones produced in the placenta during pregnancy. Majority of gestational diabetes patients control their diabetes with exercise and a healthy diet. The disease normally disappears after pregnancy."crlf  )
(assert (diabetes information)))
(if (eq ?choice 3) then (printout t crlf crlf
"Causes of diabetes" crlf
"1. Stress" crlf
"2. Obesity" crlf
"3. Family history of diabetes" crlf
"4. Improper functioning of the pancreas" crlf
"5. Previously diagnosed with gestational diabetes" crlf)
(assert (diabetes information)))
(if (eq ?choice 4)then (printout t crlf crlf
"Symptoms or warning signs of diabetes " crlf
"Learn to recognise your body's warning signs. These are the signs of diabetes: " crlf
"1. Going to the toilet more often " crlf
"2. Felling very tired and weak" crlf
"3. Feeling very thirsty" crlf
"4. Not seeing well" crlf
"5. Always hungry especially after eating" crlf
"If you are experiencing any of these symptoms you must visit your nearest clinic." crlf)
(assert (diabetes information)))
(if (eq ?choice 5) then (printout t crlf crlf
"Diabetes Treatment " crlf
"There is no treatment for diabetes. However, it can be controlled by the following lifestyle changes:" crlf
"1. Meal planning" crlf
"2. Maintaining a healthy weight" crlf
"3. Exercise program" crlf
"4. Possible use of diabetes oral medication or insulin injections" crlf
"5. Monitoring of blood glucose level" crlf
"6. Stop smoking" crlf
"7. Moderate usage of alcohol " crlf)
(assert (diabetes information)))
(if (eq ?choice 6) then (printout t crlf crlf
"Diabetes Prevention or Management" crlf
"1. Meal planning" crlf
"2. Maintaining a healthy weight" crlf
"3. Exercise program" crlf
"4. Possible use of diabetes oral medication or insulin injections" crlf
"5. Monitoring of blood glucose level" crlf
"6. Stop smoking" crlf
"7. Moderate usage of alcohol " crlf)
(assert (diabetes information)))
(if (eq ?choice 7) then (printout t crlf crlf
"Diabetes Medication" crlf
"Oral or tablets and insulin are the two types of diabetes medication" crlf)
(assert (diabetes information)))
(if (eq ?choice 8) then (printout t crlf crlf
"Diabetes Complications" crlf
"1. Hyperglycaemia or high blood sugar levels" crlf
"2. Hypoglycaemia or low blood sugar levels" crlf
"3. Diabetic Ketoacidosis or shortage of insulin" crlf
"4. Blindness" crlf
"5. Kidney failure" crlf
"6. Fungal diseases" crlf)
(assert (diabetes information)))
(assert  (user start-program)))

(defrule third-selection
  	(system exit)
   =>
    (printout t crlf
	"Thank you for using the system. Goodbye!" crlf crlf)
    (exit))

;################################ Rules ###################################



(reset)
(run)