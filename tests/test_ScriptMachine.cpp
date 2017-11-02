#include <boost/test/unit_test.hpp>
#include <script/SCMFile.hpp>
#include <script/ScriptMachine.hpp>

SCMByte data[] = {0x02, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
                  0x01, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x28, 0x00, 0x00,
                  0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

BOOST_AUTO_TEST_SUITE(ScriptMachineTests)

BOOST_AUTO_TEST_CASE(scmfile_test) {
    SCMFile f;
    f.loadFile(data, sizeof(data));

    BOOST_CHECK_EQUAL(f.getModelSection(), 0x10);
    BOOST_CHECK_EQUAL(f.getMissionSection(), 0x20);
    BOOST_CHECK_EQUAL(f.getCodeSection(), 0x28);
}

BOOST_AUTO_TEST_SUITE_END()