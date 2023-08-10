CREATE DATABASE epms_app;

USE epms_app;

--- employee: id, code, name, joining_date, job_title, salary
CREATE TABLE employee(
    id INT AUTO_INCREMENT,
    code VARCHAR(20) NOT NULL,
    name VARCHAR(512) NOT NULL,
    joining_date DATETIME NOT NULL,
    job_title VARCHAR(50) NOT NULL,
    CONSTRAINT pk_employee_id PRIMARY KEY(id),
    CONSTRAINT uk_employee_code UNIQUE(code)
);

ALTER TABLE employee
ADD salary float not null DEFAULT 0;