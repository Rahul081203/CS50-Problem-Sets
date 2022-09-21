-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Checking the database-> crime_scene_reports for any other necessary information regarding the theft

SELECT * FROM crime_scene_reports WHERE day = 28 and month = 7 and street = "Humphrey Street";

-- Got the information that the theft took place at 10:15 am at Humphrey Street Bakery and three people were interviewed

-- Checking the interviews database to find any info.

SELECT * FROM interviews WHERE day = 28 and month = 7 and transcript LIKE "%bakery%";

-- Got the information that after 10 minutes of the theft the thief got into the car in the bakery parking lot and he was also withdrawing money at the leggett street ATM before the theft
-- The thieves were planning to take the earliest flight out of fiftyville on the next day i.e. 29/07/2021 and they talked to someone on the phone within one minute of the theft

-- Checking the bakery_security_logs to check the parking lot details

SELECT * FROM bakery_security_logs WHERE year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25;

-- Got 8 records of vehicle exits within 10 minutes of theft

--  Checking for ATM withdrawals on the day of the theft at the LEGGETT STREET ATM

SELECT * FROM atm_transactions WHERE year = 2021 and day = 28 and month = 7 and atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW";

-- Got 8 people who withdrew money on the same ATM on the day of the theft and got their account number
-- Checked the schema of bank_accounts and trying to match the account holder's license plate with the ones that left the bakery to hopefully narrow the search

SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021));
-- Found all the license plate numbers of people that withdrew money from the LEGGETT STREET ATM on the day of theft

-- Checking for license_plate matches with the ones that left the bakery and printing the name and license plate numbers

SELECT name, license_plate FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25);

-- Got 4 matches of license plate numbers from the bakery and ATM

-- Checking for Phone_calls made on the day of the theft by any of these people where the duratiion was less than 60 sec.

SELECT * FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60;

-- Got 2 matches of phone calls on the day of the theft which were less than 60 sec.

-- Checking passengers records for any match with the passport number of the two people

SELECT * FROM passengers where passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60));

-- Found 4 flight records

-- Checking for the flight records of the flights boarded as found above on 29/07/2021

SELECT * FROM flights where id in(SELECT flight_id FROM passengers where passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60))) and day = 29 and month = 7 and year = 2021;

-- Found that flight number 36 left at 8:20 while flight number 18 left at 4 pm hence, the thief is the one who is in flight number 18
-- Evidence that the thief is in Flight 18

SELECT id FROM flights where id in(SELECT flight_id FROM passengers where passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60))) and day = 29 and month = 7 and year = 2021 and hour >= 10;


-- Finding the passport number from passengers in our suspect list i.e. Diana and Bruce that boarded flight id that left after the theft on the next day

SELECT passport_number from passengers where flight_id IN (SELECT id FROM flights where id in(SELECT flight_id FROM passengers where passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60))) and day = 29 and month = 7 and year = 2021 ORDER BY hour LIMIT 1) and passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60));

-- Finding the name of the thief
SELECT name as Thief from people where passport_number IN(SELECT passport_number from passengers where flight_id IN (SELECT id FROM flights where id in(SELECT flight_id FROM passengers where passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60))) and day = 29 and month = 7 and year = 2021 ORDER BY hour LIMIT 1) and passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60)));

-- Found that the thief is Bruce

-- Finding Destination Airport ID as destination_airport id of flight 36
SELECT destination_airport_id FROM flights where id in(SELECT flight_id FROM passengers where passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60))) and day = 29 and month = 7 and year = 2021 ORDER BY hour LIMIT 1;

-- Finding the city the thief escaped to
SELECT city from airports where id IN(SELECT destination_airport_id FROM flights where id in(SELECT flight_id FROM passengers where passport_number IN(SELECT passport_number from people where phone_number IN (SELECT caller FROM phone_calls where caller IN(SELECT phone_number FROM people where license_plate in (SELECT license_plate from people where id IN (SELECT person_id from bank_accounts where account_number IN (SELECT account_number from atm_transactions where atm_location LIKE "LEGGETT STREET" and transaction_type LIKE "WITHDRAW" and day = 28 and month = 7 and year = 2021))) and license_plate in (SELECT license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 7 and hour = 10 and minute >= 15 and minute <= 25)) and duration < 60))) and day = 29 and month = 7 and year = 2021 ORDER BY hour LIMIT 1);

-- Finding the helper

SELECT name as Helper from people where phone_number IN(SELECT receiver FROM phone_calls where caller IN (SELECT phone_number from people where name = "Bruce") and day = 28 and month = 7 and year = 2021);