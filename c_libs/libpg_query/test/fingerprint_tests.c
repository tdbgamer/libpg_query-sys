const char* tests[] = {
  "SELECT 1",
  "02a281c251c3a43d2fe7457dff01f76c5cc523f8c8",
  "SELECT 2",
  "02a281c251c3a43d2fe7457dff01f76c5cc523f8c8",
  "SELECT ?",
  "02a281c251c3a43d2fe7457dff01f76c5cc523f8c8",
  "SELECT $1",
  "02a281c251c3a43d2fe7457dff01f76c5cc523f8c8",
  "SELECT 1; SELECT a FROM b",
  "022d95ebf869846cd1d852ae7a62d2c927bffced73",
  "SELECT COUNT(DISTINCT id), * FROM targets WHERE something IS NOT NULL AND elsewhere::interval < now()",
  "0271480ed85a1e9f9d4b71c7eafdd632b5a6bb443f",
  "INSERT INTO test (a, b) VALUES (?, ?)",
  "02809368278814c4c8ec65e47425fdaf559483f8f6",
  "INSERT INTO test (b, a) VALUES (?, ?)",
  "02809368278814c4c8ec65e47425fdaf559483f8f6",
  "INSERT INTO test (a, b) VALUES (ARRAY[?, ?, ?, ?], ?::timestamptz), (ARRAY[?, ?, ?, ?], ?::timestamptz), (?, ?::timestamptz)",
  "02822becf2500e9e1d2843b272c1a1cd5eef353409",
  "SELECT b AS x, a AS y FROM z",
  "020a812d6225e62b9492df056a6cb92032faed2145",
  "SELECT * FROM x WHERE y IN (?)",
  "027d1fc50db3034002373ed901faf3bd0e53399373",
  "SELECT * FROM x WHERE y IN (?, ?, ?)",
  "027d1fc50db3034002373ed901faf3bd0e53399373",
  "SELECT * FROM x WHERE y IN ( ?::uuid )",
  "0296be7c7a3f1807c10199d428a575d550be953191",
  "SELECT * FROM x WHERE y IN ( ?::uuid, ?::uuid, ?::uuid )",
  "0296be7c7a3f1807c10199d428a575d550be953191",
  "PREPARE a123 AS SELECT a",
  "0219588a6aa1dbd44f69ed53c3a1d9310b429a209e",
  "EXECUTE a123",
  "02b6b0d1fe77746f47d251c04fe0de2400ca931952",
  "DEALLOCATE a123",
  "0285ab48ffa7645cf16d6a5544d4c33501ded1ee85",
  "DEALLOCATE ALL",
  "0285ab48ffa7645cf16d6a5544d4c33501ded1ee85",
  "EXPLAIN ANALYZE SELECT a",
  "02f8fdcce6547cedcaa90ffecb33c829a8cbeecce7",
  "WITH a AS (SELECT * FROM x WHERE x.y = ? AND x.z = 1) SELECT * FROM a",
  "0234e0886f3215dd300343b56771e123dc43089679",
  "CREATE TABLE types (a float(2), b float(49), c NUMERIC(2, 3), d character(4), e char(5), f varchar(6), g character varying(7))",
  "02d627474d197317c5d9ff356caa89b6d18a5647ce",
  "CREATE VIEW view_a (a, b) AS WITH RECURSIVE view_a (a, b) AS (SELECT * FROM a(1)) SELECT \"a\", \"b\" FROM \"view_a\"",
  "024666d87256b329fad0cc42ddb9688e111ed1107f",
  "VACUUM FULL my_table",
  "026e33edee478fb8051ce69601bffb50e4f31cfc8d",
  "SELECT * FROM x AS a, y AS b",
  "02e50dcae0f1a1e237231d9d8e411383ba7f25068c",
  "SELECT * FROM y AS a, x AS b",
  "02e50dcae0f1a1e237231d9d8e411383ba7f25068c",
  "SELECT x AS a, y AS b FROM x",
  "023e9771320c87e28d459a204cb9f7ec31b742143d",
  "SELECT y AS a, x AS b FROM x",
  "023e9771320c87e28d459a204cb9f7ec31b742143d",
  "SELECT x, y FROM z",
  "025bad7941491107df4b3c6bc0be2dfca4eba836d9",
  "SELECT y, x FROM z",
  "025bad7941491107df4b3c6bc0be2dfca4eba836d9",
  "INSERT INTO films (code, title, did) VALUES ('UA502', 'Bananas', 105), ('T_601', 'Yojimbo', DEFAULT)",
  "02f27f8c6bb6cdd696245cddb91d19ac5993a652f3",
  "INSERT INTO films (code, title, did) VALUES (?, ?, ?)",
  "02f27f8c6bb6cdd696245cddb91d19ac5993a652f3",
  "SELECT * FROM a",
  "02229f8b4376f20089054768237e1013753c0bf26a",
  "SELECT * FROM a AS b",
  "02229f8b4376f20089054768237e1013753c0bf26a",
  "UPDATE users SET one_thing = $1, second_thing = $2 WHERE users.id = ?",
  "020368c4589ee86e6ffb120a23f4eb229696ad6b5c",
  "UPDATE users SET something_else = $1 WHERE users.id = ?",
  "0246b178c04ead24fa3e8eb1917bb6c694b84e6d54",
  "UPDATE users SET something_else = (SELECT a FROM x WHERE uid = users.id LIMIT 1) WHERE users.id = ?",
  "02af9dd92089b870cdbb316f211da5700e0a65a084",
  "SAVEPOINT some_id",
  "02af350f3cb116f536042f0ca82205cab64eae5098",
  "RELEASE some_id",
  "028ff67731681e941af7b992d6e1129aed11b345f3",
  "PREPARE TRANSACTION 'some_id'",
  "02780d78fc4001d7c7b221dafc6a5f71d2a60bb519",
  "START TRANSACTION READ WRITE",
  "026533aebe647cd56cc75921de13fdd2b9c2fe4706",
  "DECLARE cursor_123 CURSOR FOR SELECT * FROM test WHERE id = 123",
  "0214e7d0f761512078aec86fbdeab6e06982703b79",
  "FETCH 1000 FROM cursor_123",
  "0242fed093117245ef78fbfef8b7433d23e15deb82",
  "CLOSE cursor_123",
  "02746b7bf7ec5d162462a8851f28c527553260e6c0",
  "-- nothing",
  "02da39a3ee5e6b4b0d3255bfef95601890afd80709",
  "CREATE FOREIGN TABLE ft1 () SERVER no_server",
  "02086f531f62abde7c63eeecd70f52f227009cc40a",
  "UPDATE x SET a = 1, b = 2",
  "02c888ae857224dffe91cbf2e6cc3abc6a59d38954",
  "UPDATE x SET z = now()",
  "021eb7a0cdb9a1eb9b0bd0aa41b9e23a53f2c5c8b5",
  "CREATE TEMPORARY TABLE my_temp_table (test_id integer NOT NULL) ON COMMIT DROP",
  "0282b35175ec22cfdae1f954c7c0ceaee8bc74a0c1",
  "CREATE TEMPORARY TABLE my_temp_table AS SELECT 1",
  "0257b59721145c9c48f37ca5466d756b902fb5fe9a",
};

size_t testsLength = __LINE__ - 4;