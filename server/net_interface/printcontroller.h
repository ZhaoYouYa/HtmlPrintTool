#ifndef PRINTCONTROLLER_H
#define PRINTCONTROLLER_H

#include "../printer/printmsgstation.h"
#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include <functional>
using namespace drogon;

class PrintController : public HttpController<PrintController, false> {
public:
  PrintController(PrintMsgStation &printmsgstation);

  METHOD_LIST_BEGIN
  METHOD_ADD(PrintController::TestConnect, "/testConnect", Get);
  METHOD_ADD(PrintController::GetPrintInfo, "/getprintinfo?isUpdate={1}", Get);
  METHOD_ADD(PrintController::AddOnePrintConfig, "/addoneprintconfig", Post);
  METHOD_ADD(PrintController::DelOnePrintConfig, "/deloneprintconfig?Id={1}",
             Get);
  METHOD_ADD(PrintController::UpdateOnePrintConfig, "/updateoneprintconfig",
             Post);
  METHOD_ADD(PrintController::GetPrintConfigs, "/getprintconfigs", Get);
  METHOD_ADD(PrintController::ToPrint, "/toprint", Post);
  METHOD_ADD(PrintController::GetScreenInfo, "/getscreeninfo", Get);
  METHOD_ADD(PrintController::GetPrintedPage,
             "/getPrintedPage?size={1}&page={2}", Get);
  METHOD_ADD(PrintController::GetWebsocketUrl, "/GetWebsocketUrl", Get);
  METHOD_ADD(PrintController::InsertOrUpdateWebsocketUrl,
             "/InsertOrUpdateWebsocketUrl?websocurl={1}", Get);
  METHOD_LIST_END

protected:
  void TestConnect(const HttpRequestPtr &,
                   std::function<void(const HttpResponsePtr &)> &&callback);

  void GetPrintInfo(const HttpRequestPtr &,
                    std::function<void(const HttpResponsePtr &)> &&callback,
                    bool &&isUpdate);

  void
  AddOnePrintConfig(const HttpRequestPtr &,
                    std::function<void(const HttpResponsePtr &)> &&callback);

  void
  DelOnePrintConfig(const HttpRequestPtr &,
                    std::function<void(const HttpResponsePtr &)> &&callback,
                    int &&Id);

  void
  UpdateOnePrintConfig(const HttpRequestPtr &,
                       std::function<void(const HttpResponsePtr &)> &&callback);

  void GetPrintConfigs(const HttpRequestPtr &,
                       std::function<void(const HttpResponsePtr &)> &&callback);

  void ToPrint(const HttpRequestPtr &,
               std::function<void(const HttpResponsePtr &)> &&callback);

  void GetPrintedPage(const HttpRequestPtr &,
                      std::function<void(const HttpResponsePtr &)> &&callback,
                      int &&size, int &&page);
  void GetScreenInfo(const HttpRequestPtr &,
                     std::function<void(const HttpResponsePtr &)> &&callback);

  void GetWebsocketUrl(const HttpRequestPtr &,
                       std::function<void(const HttpResponsePtr &)> &&callback);
  void InsertOrUpdateWebsocketUrl(
      const HttpRequestPtr &,
      std::function<void(const HttpResponsePtr &)> &&callback,
      std::string &&websocurl);

private:
  HttpResponsePtr ConfigResponse(const Json::Value &value);
  PrintMsgStation &_printmsgstation;
};

#endif // PRINTCONTROLLER_H
