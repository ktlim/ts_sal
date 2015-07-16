DROP TABLE IF EXISTS m2ms_TC_items;
CREATE TABLE m2ms_TC_items (
  num	int,
  item	char(32),
  type  char(32),
  size  int,
  units char(32),
  freq  float,
  range char(32),
  location char(32),
  comment char(128),
  PRIMARY KEY (num)
);
INSERT INTO m2ms_TC_items VALUES (1,"setpoint","float",16,"",0.054,"","","");
INSERT INTO m2ms_TC_items VALUES (2,"temperature","float",16,"",0.054,"","","");
INSERT INTO m2ms_TC_items VALUES (3,"error","float",16,"",0.054,"","","");
INSERT INTO m2ms_TC_items VALUES (4,"status","short",16,"",0.054,"","","");