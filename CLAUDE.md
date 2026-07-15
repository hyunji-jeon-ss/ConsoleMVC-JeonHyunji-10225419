# CLAUDE.md — ConsoleMVC-JeonHyunji-10225419

## 프로젝트 개요
콘솔 기반 MVC 스켈레톤 PoC. Model / View / Controller 패키지 구조와 역할 분리를 검증한다.

## 기술 스택 / 컨벤션
- C++20, Visual Studio(MSBuild, .vcxproj), gmock(NuGet)
- 코드 컨벤션은 상위 `Semiconductor` 폴더의 `CODE_CONVENTION.md`를 따른다.
  - 클래스: PascalCase / 메서드: camelCase / 변수: snake_case
  - public > protected > private 순서, 메서드 선언 후 멤버변수
  - 한 줄 조건문은 중괄호 없이 한 줄로 작성

## 디렉토리 구조
```
ConsoleMVCLib/    # 정적 라이브러리: model/, view/, controller/
ConsoleMVCApp/    # 콘솔 실행 파일 (main.cpp), Lib 참조
ConsoleMVCTest/   # gmock 단위 테스트, Lib 참조
```

## 테스트
- 기능 구현 시마다 gmock 기반 단위 테스트를 함께 작성한다.
- Controller가 Model/View에 의존하는 부분은 인터페이스로 분리하여 Mock 처리한다.

## 한글 인코딩 (중요)
콘솔에 한글을 출력하므로 반드시 아래 두 가지를 유지한다. 자세한 이유는 상위 `Semiconductor` 폴더의 `CLAUDE.md` 참고.
1. 모든 `.vcxproj`의 각 ClCompile 설정에 `<AdditionalOptions>/utf-8 %(AdditionalOptions)</AdditionalOptions>` 적용
2. `ConsoleMVCApp/main.cpp`에서 `SetConsoleOutputCP(CP_UTF8)` / `SetConsoleCP(CP_UTF8)` 호출 유지

## 커밋 컨벤션
`COMMIT_CONVENTION.md`를 따른다. 커밋 메시지는 `<헤더> 변경 내용` 형식이며, 헤더는 `<FEATURE>`/`<FIX>`/`<DOCS>`/`<STYLE>`/`<REFACTOR>`/`<TEST>`/`<CHORE>` 중 하나만 사용한다.

## 빌드/실행
Visual Studio에서 솔루션을 열어 빌드/실행한다.
