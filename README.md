# ConsoleMVC-JeonHyunji-10225419

반도체 시료 생산주문관리 시스템 개인과제 — **[미션1] PoC: MVC 스켈레톤 코드**

## 목적
콘솔 애플리케이션의 Model / Controller / View 패키지 구조와 역할 분리를 검증하는 PoC.

## 기술 스택
- C++20, Visual Studio (MSBuild, .vcxproj)
- gmock (NuGet, v1.11.0) 기반 단위 테스트

## 구조
```
ConsoleMVC.sln
ConsoleMVCLib/        # 정적 라이브러리: MVC 핵심 로직
  model/               Item, ItemModel (데이터 및 상태)
  view/                IView, ConsoleView (콘솔 출력)
  controller/          IInputReader, ConsoleInputReader, MainController (입력 처리/중개)
ConsoleMVCApp/         # 콘솔 실행 파일 (main.cpp), ConsoleMVCLib 참조
ConsoleMVCTest/        # gmock 단위 테스트, ConsoleMVCLib 참조
```
View/Controller의 의존성은 `IView`/`IInputReader` 인터페이스로 분리되어 있어, 테스트에서 gmock으로 손쉽게 대체(Mock)할 수 있다.

## 빌드 방법 (Visual Studio)
1. `ConsoleMVC.sln`을 Visual Studio로 연다.
2. 처음 열면 `ConsoleMVCTest` 프로젝트의 NuGet 패키지(gmock 1.11.0)가 자동으로 복원된다.
   - 자동 복원이 안 되면: 솔루션 탐색기에서 솔루션 우클릭 → **NuGet 패키지 복원**
3. 상단 플랫폼/구성을 **Debug / x64** (또는 Release / x64)로 맞춘다.
4. 솔루션 빌드: 메뉴 **빌드 → 솔루션 빌드** (`Ctrl+Shift+B`)

## 실행 방법
- **콘솔 앱 실행**: `ConsoleMVCApp`를 시작 프로젝트로 설정 후 `F5`(디버그 시작) 또는 `Ctrl+F5`(디버그 없이 시작)
  - 메뉴에서 `1`(항목 등록), `2`(항목 목록), `0`(종료) 입력으로 동작 확인
- **테스트 실행**: `ConsoleMVCTest`를 시작 프로젝트로 설정 후 `Ctrl+F5`로 직접 실행하면 콘솔에 gtest/gmock 테스트 결과가 출력된다.
  - 또는 Visual Studio의 **테스트 탐색기**(테스트 → 테스트 탐색기)에서 개별 테스트 실행 가능

## 관련 문서
- 상위 저장소의 `PRD.md`, `PLAN.md` Phase 1 참고
