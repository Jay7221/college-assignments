CREATE DATABASE ads1;
USE ads1;
SET SQL_SAFE_UPDATES = 0;
create table studentTable(
prn int,
studentName varchar(10),
marks float8
);
alter table studentTable modify column prn varchar(100);
alter table studentTable modify column prn varchar (100) PRIMARY KEY;
alter table studentTable modify column studentName varchar(255);

insert  studentTable values('21510026','Jay Shirgupe',35);
insert  studentTable values('21510028','Rahul Revanna',35);
insert  studentTable values('21510029','Chinmay Patil',35);
insert  studentTable values('21510040','Aditya Kumbhar',35);
insert  studentTable values('21510043','Prathamesh Basapure',35);

select * from studentTable;

select studentName from studentTable;
select count(*) from studentTable;

select prn from studentTable where  studentName LIKE '%Rahul%';
select studentName from studentTable where prn='21510028';

select * from studentTable order by studentName asc;
select * from studentTable order by studentName desc;

UPDATE studentTable
SET studentName = 'Rotractor Rahul Rajendra Revanna'
WHERE prn = '21510028';

select * from myTable limit 3;
select * from myTable limit 3 offset 2;
select max(marks) from myTable ;
select min(marks) from myTable ;
select avg(marks) from myTable ;
select sum(marks) from myTable ;