# CLAUDE.md — ConsoleMVC-JeonHyunji-10225419

## 프로젝트 개요
콘솔 기반 MVC 스켈레톤 PoC. Model / View / Controller 패키지 구조와 역할 분리를 검증한다.

## 기술 스택 / 컨벤션
- C++20, Visual Studio(MSBuild, .vcxproj), gmock(NuGet)
- 코드 컨벤션은 상위 `Semiconductor` 폴더의 `CODE_CONVENTION.md`를 따른다.
  - 클래스: PascalCase / 메서드: camelCase / 변수: snake_case
  - public > protected > private 순서, 메서드 선언 후 멤버변수
  - 한 줄 조건문은 중괄호 없이 한 줄로 작성

## 디렉토리 구조 (예정)
```
model/       # 데이터 및 상태
view/        # 콘솔 출력 담당
controller/  # 입력 처리 및 Model-View 중개
test/        # gmock 기반 단위 테스트
```

## 테스트
- 기능 구현 시마다 gmock 기반 단위 테스트를 함께 작성한다.
- Controller가 Model/View에 의존하는 부분은 인터페이스로 분리하여 Mock 처리한다.

## 빌드/실행
Visual Studio에서 솔루션을 열어 빌드/실행한다.
