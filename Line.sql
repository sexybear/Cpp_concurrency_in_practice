CREATE TABLE `gd_line` (
    `Line_name` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Stop_cnt` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Line_type` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci'
)
COLLATE='utf8mb4_unicode_ci'
ENGINE=InnoDB
;
CREATE TABLE `gd_weather` (
    `Date_time` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Weather` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Temperature` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Wind_direction_force` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci'
)
COLLATE='utf8mb4_unicode_ci'
ENGINE=InnoDB
;
CREATE TABLE `gd_train_log` (
    `Use_city` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Line_name` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Terminal_id` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Card_id` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Create_city` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Deal_time` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci',
    `Card_type` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_unicode_ci'
)
COLLATE='utf8mb4_unicode_ci'
ENGINE=InnoDB
;
LOAD DATA LOCAL INFILE
    'E:\\BaiduYunDownload\\1108-gz-bus\\1106\\gd_weather_report.txt'
    IGNORE INTO TABLE `gz_bus`.`gd_weather`
    CHARACTER SET utf8
    FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r\n'
    (`Date_time`, `Weather`, `Temperature`, `Wind_direction_force`);
/* 184 rows imported in 0.078 seconds. */
SHOW WARNINGS;
LOAD DATA LOCAL INFILE
    'E:\\BaiduYunDownload\\1108-gz-bus\\1106\\gd_line_desc.txt'
    IGNORE INTO TABLE `gz_bus`.`gd_line`
    CHARACTER SET utf8
    FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r\n'
    (`Line_name`, `Stop_cnt`, `Line_type`);
/* 21 rows imported in 0.140 seconds. */
SHOW WARNINGS;
LOAD DATA LOCAL INFILE
    'E:\\BaiduYunDownload\\1108-gz-bus\\1106\\gd_train_data.txt'
    INTO TABLE `gz_bus`.`gd_train_log`
    CHARACTER SET utf8
    FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r\n'
    (`Use_city`, `Line_name`, `Terminal_id`, `Card_id`, `Create_city`, `Deal_time`, `Card_type`);
/* 8,926,605 rows imported in 262.705 seconds. */
SHOW WARNINGS;