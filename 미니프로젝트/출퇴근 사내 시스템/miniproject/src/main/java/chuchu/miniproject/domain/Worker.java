package chuchu.miniproject.domain;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.time.LocalDate;

@NoArgsConstructor
@Getter
@Setter
@Entity
public class Worker {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false, length = 25)
    private String name;


    @Column(nullable = false, length = 25)
    private String teamName;

    @Enumerated(EnumType.STRING)
    @Column(nullable = false)
    private Role role;

    @Column
    private LocalDate birthday;

    @Column(nullable = false)
    private LocalDate workStartDate;


    public Worker(String name, String teamName, Role role, LocalDate birthday, LocalDate workStartDate) {
        if(name == null || name.trim().isEmpty()){
            throw new IllegalArgumentException(String.format("유효하지 않은 이름입니다: %s",name));
        }
        if(teamName == null || teamName.trim().isEmpty()){
            throw new IllegalArgumentException(String.format("유효하지 않은 팀 이름입니다: %s",teamName));
        }
        if(role == null){
            throw new IllegalArgumentException("유효하지 않은 role 입니다.");
        }
        if(birthday.isAfter(LocalDate.now())){
            throw new IllegalArgumentException("생년월일은 미래날짜가 될 수 없습니다.");
        }
        if(workStartDate == null){
            throw new IllegalArgumentException("유효하지 않은 입사일 입니다.");
        }
        if(workStartDate.isAfter(LocalDate.now())){
            throw new IllegalArgumentException("입사일은 미래날짜가 될 수 없습니다.");
        }
        if(birthday.isBefore(LocalDate.of(1900, 1, 1))) {
            throw new IllegalArgumentException("생년월일이 너무 오래되었습니다.");
        }
        this.name = name;
        this.teamName = teamName;
        this.role = role;
        this.birthday = birthday;
        this.workStartDate = workStartDate;
    }


}
