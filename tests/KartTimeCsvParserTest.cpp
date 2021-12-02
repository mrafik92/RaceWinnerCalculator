

#include <KartPassingTime.h>
#include <gtest/gtest.h>
#include "KartPassingTimeCsvParser.h"

class KartTimeCsvParserTest : public ::testing::Test
{
public:
    KartTimeCsvParserTest() = default;

    std::shared_ptr<KartPassingTimeCsvParser> parser{};

};


TEST_F(KartTimeCsvParserTest, testParsing) {


    std::string csv = """"
                      "12,12:44:22\n"
                      "11,00:00:00\n"
                      "2,22:22:33"
                      """";

    parser = std::make_shared<KartPassingTimeCsvParser>(csv);
    ASSERT_EQ(3, parser->getKartTimings().size());

}